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


#define PIN_ROW1	3U
#define PIN_ROW2	13U
#define PIN_ROW3	25U
#define PIN_ROW4	24U

#define GPIO_ROW1	GPIOD
#define GPIO_ROW2	GPIOD
#define GPIO_ROW3	GPIOE
#define GPIO_ROW4	GPIOE

#define PORT_ROW1	PORTD
#define PORT_ROW2	PORTD
#define PORT_ROW3	PORTE
#define PORT_ROW4	PORTE

#define PIN_COL1	0U
#define PIN_COL2	1U
#define PIN_COL3	3U
#define PIN_COL4	2U
#define PIN_COL5	0U
#define PIN_COL6	2U
#define PIN_COL7	5U
#define PIN_COL8	25U

#define GPIO_COL1	GPIOC
#define GPIO_COL2	GPIOD
#define GPIO_COL3	GPIOD
#define GPIO_COL4	GPIOD
#define GPIO_COL5	GPIOD
#define GPIO_COL6	GPIOC
#define GPIO_COL7	GPIOC
#define GPIO_COL8	GPIOA

#define PORT_COL1	PORTC
#define PORT_COL2	PORTD
#define PORT_COL3	PORTD
#define PORT_COL4	PORTD
#define PORT_COL5	PORTD
#define PORT_COL6	PORTC
#define PORT_COL7	PORTC
#define PORT_COL8	PORTA


void Init_KeyboardMatrix(void);
uint32_t ScanKeys(void);

#endif /* SCANNER_KEYMATRIX_H_ */
