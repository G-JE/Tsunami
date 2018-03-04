/*
 * AusdioOut.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "AudioOut.h"

volatile uint16_t* AudioRegister;


void Init_Dac(void){
	dac_config_t dacConfig;

	DAC_GetDefaultConfig(&dacConfig);
	DAC_Init(AUDIO_DAC, &dacConfig);

	DAC_Enable(AUDIO_DAC, true);
	DAC_SetBufferReadPointer(AUDIO_DAC, 0u);
}

void UpdateDac(uint16_t value){
	DAC_SetBufferValue(AUDIO_DAC, 0u, value);
}

