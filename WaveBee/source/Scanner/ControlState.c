/*
 * ButtonState.c
 *
 *  Created on: Mar 3, 2018
 *      Author: ericksong
 */

#include <Scanner/ControlState.h>

void InitButtons(void){
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
