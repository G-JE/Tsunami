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

void Init_Ftm(void){
	ftm_config_t ftmConfig;

	FTM_GetDefaultConfig(&ftmConfig);
	ftmConfig.prescale = kFTM_Prescale_Divide_4;
	FTM_Init(DAC_TRIG, &ftmConfig);
	FTM_SetTimerPeriod(DAC_TRIG, USEC_TO_COUNT(128u, TRIGGER_CLKSRC));
	FTM_EnableInterrupts(DAC_TRIG, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(DAC_TRIG_IRQ);
}

void StartPlayback(volatile uint16_t* audio){

	// get a handle on the 16-bit value that will be updated by the controller
	AudioRegister = audio;

	FTM_SetTimerPeriod(DAC_TRIG, USEC_TO_COUNT(128u, TRIGGER_CLKSRC));
	FTM_EnableInterrupts(DAC_TRIG, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(DAC_TRIG_IRQ);
	FTM_StartTimer(DAC_TRIG, kFTM_SystemClock);
}

void UpdateDac(uint16_t value){
	DAC_SetBufferValue(AUDIO_DAC, 0u, value);
}

void DAC_TRIG_Callback(void){
	FTM_ClearStatusFlags(DAC_TRIG, kFTM_TimeOverflowFlag);

	// Right shift information on the DAC by 4 to compress to 12 bits
	UpdateDac(*AudioRegister >> 4);

}
