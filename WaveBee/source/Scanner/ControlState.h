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
#include "fsl_adc16.h"
#include "math.h"


#define RECORD_BUTTON_PIN 8u
#define RECORD_BUTTON_PORT PORTA
#define RECORD_BUTTON_GPIO GPIOA

#define ENCODER_PINA 1u
#define ENCODER_PORTA PORTD
#define ENCODER_GPIOA GPIOD

#define ENCODER_PINB 16u
#define ENCODER_PORTB PORTC
#define ENCODER_GPIOB GPIOC

#define ENCODER_IRQ2 PORTC_IRQn
#define ENCODER_HANDLER2 PORTC_IRQHandler

#define RECORD_HANDLER PORTA_IRQHandler
#define RECORD_IRQ PORTA_IRQn
#define ENCODER_HANDLER PORTD_IRQHandler
#define ENCODER_IRQ PORTD_IRQn

#define ADC_BASE1 ADC1
#define POSITION_SLIDER_CHANNEL 13u
#define SLIDER_GROUP 0u
#define LENGTH_SLIDER_CHANNEL 12u
#define ATTACK_SLIDER_CHANNEL 11u
#define DECAY_SLIDER_CHANNEL 10u
#define LENGTH_SLIDER_GROUP 0u

#define ADC_BASE0 ADC0
#define SUSTAIN_SLIDER_CHANNEL 13
#define RELEASE_SLIDER_CHANNEL 12u

#define RECORD_MASK  (1u << RECORD_BUTTON_PIN)
#define ENCODER_MASK (1u << ENCODER_PINA) | (1u << ENCODER_PINB)
enum ControlState {
	NOP,
	RECORDING,
	ENCODER_CW,
	ENCODER_CCW,
	UPDATE_INDEXES
};

enum States {
	RECORD
};

float GetPosition(void);
float GetLength(void);
void InitControls(void);
StateInstance GetControlState(void);
void UpdateControlState(uint8_t value);
void UpdateADCValues(void);

#endif /* SCANNER_CONTROLSTATE_H_ */
