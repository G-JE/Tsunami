/*
 * AudioStreamer.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */
#include <Audio/AudioStreamer.h>

sai_edma_handle_t txHandle = {0};
edma_handle_t dmaTxHandle = {0};
sai_edma_handle_t rxHandle = {0};
edma_handle_t dmaRxHandle = {0};
static sai_transfer_format_t format = {0};
da7212_handle_t codecHandle = {0};
volatile bool istxFinished = false;
volatile bool isrxFinished = false;
volatile uint32_t beginCount = 0;
volatile uint32_t sendCount = 0;
volatile uint32_t receiveCount = 0;
i2c_master_handle_t i2cHandle = {{0, 0, kI2C_Write, 0, 0, NULL, 0}, 0, 0, NULL, NULL};
static uint16_t audioBuff[80000];

void rxCallback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData)
{
    sai_transfer_t xfer = {0};

    receiveCount++;

    if (receiveCount == beginCount)
    {
        isrxFinished = true;
        SAI_TransferTerminateReceiveEDMA(base, handle);
        receiveCount = 0;
    }
    else
    {

		xfer.data = (uint8_t *) audioBuff + ((receiveCount - 1U) * BUFFER_SIZE);
		xfer.dataSize = BUFFER_SIZE;
		SAI_TransferReceiveEDMA(base, handle, &xfer);
    }
}

void Init_Dialog7212(void){
    sai_config_t config;
    uint32_t mclkSourceClockHz = 0U;
    edma_config_t dmaConfig = {0};

    i2c_master_config_t i2cConfig = {0};
    uint32_t i2cSourceClock;

    EDMA_GetDefaultConfig(&dmaConfig);
    EDMA_Init(MIC_DMA, &dmaConfig);
    EDMA_CreateHandle(&dmaTxHandle, MIC_DMA, Dialog_TX_SOURCE);
    EDMA_CreateHandle(&dmaRxHandle, MIC_DMA, Dialog_RX_CHANNEL);

    DMAMUX_Init(MIC_DMAMUX);
    DMAMUX_SetSource(MIC_DMAMUX, Dialog_TX_SOURCE, (uint8_t)Dialog_TX_SOURCE);
    DMAMUX_EnableChannel(MIC_DMAMUX, Dialog_TX_SOURCE);
    DMAMUX_SetSource(MIC_DMAMUX, Dialog_RX_CHANNEL, (uint8_t)Dialog_RX_SOURCE);
    DMAMUX_EnableChannel(MIC_DMAMUX, Dialog_RX_CHANNEL);

    /* Init SAI module */
    /*
     * config.masterSlave = kSAI_Master;
     * config.mclkSource = kSAI_MclkSourceSysclk;
     * config.protocol = kSAI_BusLeftJustified;
     * config.syncMode = kSAI_ModeAsync;
     * config.mclkOutputEnable = true;
     */
    SAI_TxGetDefaultConfig(&config);
    SAI_TxInit(Dialog_SAI, &config);

    /* Initialize SAI Rx */
    SAI_RxGetDefaultConfig(&config);
    SAI_RxInit(Dialog_SAI, &config);

    /* Configure the audio format */
	format.bitWidth = kSAI_WordWidth16bits;
	format.channel = 0U;
	format.sampleRate_Hz = SAMPLE_RATE;

	format.masterClockHz = OVER_SAMPLE_RATE * format.sampleRate_Hz;

	format.protocol = config.protocol;
	format.stereo = kSAI_Stereo;

	format.watermark = FSL_FEATURE_SAI_FIFO_COUNT / 2U;

	/* Configure Sgtl5000 I2C */
	codecHandle.base = Dialog_I2C;
	codecHandle.i2cHandle = &i2cHandle;
	i2cSourceClock = I2C_CLK_FREQ;

	/*
	 * i2cConfig.baudRate_Bps = 100000U;
	 * i2cConfig.enableStopHold = false;
	 * i2cConfig.glitchFilterWidth = 0U;
	 * i2cConfig.enableMaster = true;
	 */
	I2C_MasterGetDefaultConfig(&i2cConfig);
	I2C_MasterInit(Dialog_I2C, &i2cConfig, i2cSourceClock);
	I2C_MasterTransferCreateHandle(Dialog_I2C, &i2cHandle, NULL, NULL);

	DA7212_Init(&codecHandle, NULL);
	DA7212_ConfigAudioFormat(&codecHandle, format.sampleRate_Hz, format.masterClockHz, format.bitWidth);
	DA7212_ChangeOutput(&codecHandle, kDA7212_Output_HP);

	SAI_TransferRxCreateHandleEDMA(Dialog_SAI, &rxHandle, rxCallback, NULL, &dmaRxHandle);

	mclkSourceClockHz = Dialog_CLK_FREQ;
	SAI_TransferRxSetFormatEDMA(Dialog_SAI, &rxHandle, &format, mclkSourceClockHz, format.masterClockHz);

	/* Enable interrupt to handle FIFO error */
	SAI_RxEnableInterrupts(Dialog_SAI, kSAI_FIFOErrorInterruptEnable);
	EnableIRQ(Dialog_RX_IRQ);

	DA7212_ChangeInput(&codecHandle, kDA7212_Input_MIC1_Dig);
}

uint16_t* StartStream(uint8_t time_s){

	sai_transfer_t xfer = {0};

	/* First clear the buffer */
	memset(audioBuff, 0, sizeof audioBuff);
	istxFinished = false;
	isrxFinished = false;
	sendCount = 0;
	receiveCount = 0;

	/* Compute the begin count */
	beginCount = time_s * SAMPLE_RATE / BUFFER_SIZE;

	xfer.dataSize = BUFFER_SIZE;

	/* Start record first */
	xfer.data = (uint8_t *) audioBuff;
	SAI_TransferReceiveEDMA(Dialog_SAI, &rxHandle, &xfer);

	/* Wait for record and playback finished */
	while (isrxFinished != true){}

	return audioBuff;
}

void Dialog_UserTxIRQHandler(void)
{
    /* Clear the FEF flag */
    SAI_TxClearStatusFlags(Dialog_SAI, kSAI_FIFOErrorFlag);
    SAI_TxSoftwareReset(Dialog_SAI, kSAI_ResetTypeFIFO);

    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */

    __DSB();
}

void Dialog_UserRxIRQHandler(void)
{
    SAI_RxClearStatusFlags(Dialog_SAI, kSAI_FIFOErrorFlag);
    SAI_RxSoftwareReset(Dialog_SAI, kSAI_ResetTypeFIFO);

    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */

    __DSB();
}
