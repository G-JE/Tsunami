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
#include "DataStructures/Structures.h"
#include "Audio/AudioStreamer.h"
#include "fsl_debug_console.h"

#define RECORD_BUTTON_PIN 8u
#define RECORD_BUTTON_PORT PORTA
#define RECORD_BUTTON_GPIO GPIOA
#define RECORD_BUTTON_HANDLER PORTA_IRQHandler
#define RECORD_BUTTON_IRQ PORTA_IRQn

enum ControlState {
		NOT_RECORDING,
		RECORDING,
};

enum States {
	RECORD
};

void InitButtons(void);
StateInstance GetControlState(void);
void UpdateControlState(uint8_t param, uint8_t value);

#endif /* SCANNER_CONTROLSTATE_H_ */
