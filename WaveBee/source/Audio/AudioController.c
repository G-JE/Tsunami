/*
 * AudioController.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

uint32_t RecordingLength = 0;
bool recording = false;

void RECORD_BUTTON_HANDLER(void){
	GPIO_PortClearInterruptFlags(RECORD_BUTTON_GPIO, (1U << RECORD_BUTTON_PIN));

	//Trigger the recording to start and end based on rising or falling edge
	if(!recording){
		recording = true;
		printf("recording\r\n");
	}
	else{
		recording = false;
		printf("stopped recording\r\n");
	}
	// this is needed for M4 ARM arch
    __DSB();
}

void Init_Buttons(void){
	port_pin_config_t buttonConfig = {
			/* Internal pull-up resistor is enabled */
			kPORT_PullUp,
			/* Fast slew rate is configured */
			kPORT_FastSlewRate,
			/* Passive filter is disabled */
			kPORT_PassiveFilterDisable,
			/* Open drain is disabled */
			kPORT_OpenDrainDisable,
			/* Low drive strength is configured */
			kPORT_LowDriveStrength,
			/* Pin is configured as PTA10 */
			kPORT_MuxAsGpio,
			/* Pin Control Register fields [15:0] are not locked */
			kPORT_UnlockRegister
	};
	gpio_pin_config_t inputConfig = {kGPIO_DigitalInput, 0u};
	PORT_SetPinConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, &buttonConfig);
	PORT_SetPinInterruptConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, kPORT_InterruptEitherEdge);
	EnableIRQ(RECORD_BUTTON_IRQ);
	GPIO_PinInit(RECORD_BUTTON_GPIO, RECORD_BUTTON_PIN, &inputConfig);
}
