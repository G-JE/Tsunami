/*
 * KeyMatrix.h
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#ifndef SCANNER_KEYMATRIX_H_
#define SCANNER_KEYMATRIX_H_

#include <stdio.h>
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "math.h"

#define PIN_ROW1	27U
#define PIN_ROW2	26U
#define PIN_ROW3	6U
#define PIN_ROW4	7U

#define GPIO_ROW1	GPIOA
#define GPIO_ROW2	GPIOA
#define GPIO_ROW3	GPIOA
#define GPIO_ROW4	GPIOA

#define PORT_ROW1	PORTA
#define PORT_ROW2	PORTA
#define PORT_ROW3	PORTA
#define PORT_ROW4	PORTA

#define PIN_COL1	12U
#define PIN_COL2	13U
#define PIN_COL3	25U
#define PIN_COL4	24U
#define PIN_COL5	0U
#define PIN_COL6	11U
#define PIN_COL7	10U
#define PIN_COL8	0U

#define GPIO_COL1	GPIOD
#define GPIO_COL2	GPIOD
#define GPIO_COL3	GPIOE
#define GPIO_COL4	GPIOE
#define GPIO_COL5	GPIOC
#define GPIO_COL6	GPIOB
#define GPIO_COL7	GPIOB
#define GPIO_COL8	GPIOD

#define PORT_COL1	PORTD
#define PORT_COL2	PORTD
#define PORT_COL3	PORTE
#define PORT_COL4	PORTE
#define PORT_COL5	PORTC
#define PORT_COL6	PORTB
#define PORT_COL7	PORTB
#define PORT_COL8	PORTD


void Init_KeyboardMatrix(void);
uint32_t ScanKeys(void);
void UpdateActiveKeys(void);
void StartGate(uint8_t index);
void EndGate(uint8_t index);

#endif /* SCANNER_KEYMATRIX_H_ */
