/*
 * KeyMatrix.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */

#include "KeyMatrix.h"

// Mapped indexes for columns and rows of the key matrix for controlling individual pins

GPIO_Type* COL_PORTS[8] = { GPIO_COL1, GPIO_COL2, GPIO_COL3, GPIO_COL4,
							GPIO_COL5, GPIO_COL6, GPIO_COL7, GPIO_COL8 };
uint8_t COL_PINS[8]		= {	PIN_COL1, PIN_COL2, PIN_COL3, PIN_COL4,
							PIN_COL5, PIN_COL6, PIN_COL7, PIN_COL8 };


GPIO_Type* ROW_PORTS[4] = { GPIO_ROW1, GPIO_ROW2, GPIO_ROW3, GPIO_ROW4 };
uint8_t ROW_PINS[4] 	= { PIN_ROW1, PIN_ROW2, PIN_ROW3, PIN_ROW4 };


void Init_KeyboardMatrix(void){
	// Initialize all rows as outputs and all columns as inputs

	gpio_pin_config_t pinAsOutput = {kGPIO_DigitalOutput, 0U};
	gpio_pin_config_t pinAsInput = {kGPIO_DigitalInput};

	// Columns are inputs to be read from
	for(uint8_t i = 0; i < 8; i++){
		GPIO_PinInit(COL_PORTS[i], COL_PINS[i], &pinAsInput);
	}

	// Rows are outputs to be driven
	for(uint8_t i = 0; i < 4; i++){
		GPIO_PinInit(ROW_PORTS[i], ROW_PINS[i], &pinAsOutput);
	}
}

// function used for determining what keys are pressed
uint32_t ScanKeys(void){

	uint8_t position = 0;
	uint32_t active = 0;
	uint32_t keyData = 0;

	for(uint8_t i = 0; i < 4; i++){
		// activate the row
		GPIO_PinWrite(ROW_PORTS[i], ROW_PINS[i], 1u);

		for(uint8_t j = 0; j < 8; j++){
			// read of a column has a key press
			active = GPIO_PinRead(COL_PORTS[j], COL_PINS[j]);
			if(active){
				// clear active bits and move a 1 to the key position
				active = (active & 0) | (1u << position);

				// pack all of the key information into a 32 bit register
				keyData |= active;
			}
			position++;
		}
		// deactivate the pin row
		GPIO_PinWrite(ROW_PORTS[i], ROW_PINS[i], 0u);
	}

	//output the key data as a debug method
	printf("%b\r\n", keyData);

	return keyData;
}
