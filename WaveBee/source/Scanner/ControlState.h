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

#define ENCODER_PINA 1u
#define ENCODER_PORTA PORTD
#define ENCODER_GPIOA GPIOD

#define ENCODER_PINB 3u
#define ENCODER_PORTB PORTD
#define ENCODER_GPIOB GPIOD


#define RECORD_HANDLER PORTA_IRQHandler
#define RECORD_IRQ PORTA_IRQn
#define ENCODER_HANDLER PORTD_IRQHandler
#define ENCODER_IRQ PORTD_IRQn

#define RECORD_MASK  (1u << RECORD_BUTTON_PIN)
#define ENCODER_MASK (1u << ENCODER_PINA) | (1u << ENCODER_PINB)
enum ControlState {
		NOP,
		RECORDING,
		ENCODER_CW,
		ENCODER_CCW
};

enum States {
	RECORD
};

void InitControls(void);
StateInstance GetControlState(void);
void UpdateControlState(uint8_t param, uint8_t value);

#endif /* SCANNER_CONTROLSTATE_H_ */
