/*
 * ButtonState.h
 *
 *  Created on: Mar 3, 2018
 *      Author: ericksong
 */

#ifndef SCANNER_CONTROLSTATE_H_
#define SCANNER_CONTROLSTATE_H_

#include "fsl_port.h"
#include "fsl_gpio.h"

#define RECORD_BUTTON_PIN 8u
#define RECORD_BUTTON_PORT PORTA
#define RECORD_BUTTON_GPIO GPIOA
#define RECORD_BUTTON_HANDLER PORTA_IRQHandler
#define RECORD_BUTTON_IRQ PORTA_IRQn

enum ControlState {
		RECORDING,
		NOT_RECORDING
};

void InitButtons(void);
uint8_t GetControlState(void);
#endif /* SCANNER_CONTROLSTATE_H_ */
