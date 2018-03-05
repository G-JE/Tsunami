/*
 * KeyMatrix.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */

#include "KeyMatrix.h"

// Mapped indexes for columns and rows of the key matrix for controlling individual pins

GPIO_Type* COL_GPIO[8] = { GPIO_COL1, GPIO_COL2, GPIO_COL3, GPIO_COL4,
							GPIO_COL5, GPIO_COL6, GPIO_COL7, GPIO_COL8 };
PORT_Type* COL_PORTS[8] = { PORT_COL1, PORT_COL2, PORT_COL3, PORT_COL4,
							PORT_COL5, PORT_COL6, PORT_COL7, PORT_COL8 };
uint8_t COL_PINS[8]		= {	PIN_COL1, PIN_COL2, PIN_COL3, PIN_COL4,
							PIN_COL5, PIN_COL6, PIN_COL7, PIN_COL8 };

PORT_Type* ROW_PORTS[4] = { PORT_ROW1, PORT_ROW2, PORT_ROW3, PORT_ROW4 };
GPIO_Type* ROW_GPIO[4] = { GPIO_ROW1, GPIO_ROW2, GPIO_ROW3, GPIO_ROW4 };
uint8_t ROW_PINS[4] 	= { PIN_ROW1, PIN_ROW2, PIN_ROW3, PIN_ROW4 };

void InitKeyboardMatrix(void){

	// Initialize all rows as outputs and all columns as inputs
	port_pin_config_t gpio_pin = { kPORT_PullDown,
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
									kPORT_UnlockRegister};

	gpio_pin_config_t pinAsOutput = {kGPIO_DigitalOutput, 1U};
	gpio_pin_config_t pinAsInput = {kGPIO_DigitalInput};

	// do some pin muxing here
	for(uint8_t i = 0; i < 8; i++)
		PORT_SetPinConfig(COL_PORTS[i], COL_PINS[i], &gpio_pin);
	for(uint8_t i = 0; i < 4; i++)
		PORT_SetPinConfig(ROW_PORTS[i], ROW_PINS[i], &gpio_pin);

	// Columns are inputs to be read from
	for(uint8_t i = 0; i < 8; i++)
		GPIO_PinInit(COL_GPIO[i], COL_PINS[i], &pinAsOutput);

	// Rows are outputs to be driven
	for(uint8_t i = 0; i < 4; i++)
		GPIO_PinInit(ROW_GPIO[i], ROW_PINS[i], &pinAsInput);
}

// function used for determining what keys are pressed
uint32_t ScanKeys(void){

	uint8_t position = 0;
	uint32_t active = 0;
	uint32_t keyData = 0;

	for(uint8_t i = 0; i < 8; i++){
		// activate the column
		GPIO_PinWrite(COL_GPIO[i], COL_PINS[i], 1u);

		for(uint8_t j = 0; j < 4; j++){
			// read of a row has a key press
			active = GPIO_PinRead(ROW_GPIO[j], ROW_PINS[j]);
			position = i + (j*8);
			if(active){
				// clear active bits and move a 1 to the key position
				active = (active & 0) | (1u << position);

				// pack all of the key information into a 32 bit register
				keyData |= active;
			}
		}
		// deactivate the pin column
		GPIO_PinWrite(COL_GPIO[i], COL_PINS[i], 0u);

		// requires a slight delay to not have false triggers
		uint8_t delay = 10;
		while(delay--);
	}
	return keyData;
}


