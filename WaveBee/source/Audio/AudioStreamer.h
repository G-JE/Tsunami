/*
 * AudioStreamer.h
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "fsl_sai_edma.h"
#include "fsl_dialog7212.h"
#include "fsl_dmamux.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
//#include "Audio/PitchShift.h"

#ifndef AUDIOSTREAM_AUDIOSTREAMER_H_
#define AUDIOSTREAM_AUDIOSTREAMER_H_

/* SAI and I2C instance and clock */
#define Dialog_SAI I2S0
#define Dialog_I2C I2C1
#define Dialog_SAI_CLKSRC kCLOCK_CoreSysClk
#define Dialog_CLK_FREQ CLOCK_GetFreq(kCLOCK_CoreSysClk)
#define I2C_CLKSRC kCLOCK_BusClk
#define I2C_CLK_FREQ CLOCK_GetFreq(kCLOCK_BusClk)
#define MIC_DMA DMA0
#define MIC_DMAMUX DMAMUX
#define Dialog_TX_CHANNEL (0U)
#define Dialog_RX_CHANNEL (1U)
#define Dialog_TX_SOURCE kDmaRequestMux0I2S0Tx
#define Dialog_RX_SOURCE kDmaRequestMux0I2S0Rx
#define Dialog_UserTxIRQHandler I2S0_Tx_IRQHandler
#define Dialog_UserRxIRQHandler I2S0_Rx_IRQHandler
#define Dialog_TX_IRQ I2S0_Tx_IRQn
#define Dialog_RX_IRQ I2S0_Rx_IRQn

#define I2C_RELEASE_SDA_PORT PORTC
#define I2C_RELEASE_SCL_PORT PORTC
#define I2C_RELEASE_SDA_GPIO GPIOC
#define I2C_RELEASE_SDA_PIN 11U
#define I2C_RELEASE_SCL_GPIO GPIOC
#define I2C_RELEASE_SCL_PIN 10U
#define I2C_RELEASE_BUS_COUNT 100U
#define OVER_SAMPLE_RATE (384U)
#define SAMPLE_RATE (kSAI_SampleRate8KHz)
#define BUFFER_SIZE (512)
#define BUFFER_NUM (4)


void rxCallback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData);
void txCallback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData);
void Init_Dialog7212(void);
uint32_t StartRecording(void);
void EndRecording(void);
uint16_t GetAudioData(uint32_t index);
void FindMaximum(void);
uint16_t GetMaximum(void);
uint16_t* GetAudio(void);

#endif /* AUDIOSTREAM_AUDIOSTREAMER_H_ */
