/*
 * AusdioOut.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "AudioOut.h"

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
	FTM_Init(DAC_TRIG, &ftmConfig);
	FTM_SetTimerPeriod(DAC_TRIG, USEC_TO_COUNT(16u, TRIGGER_CLKSRC));
	FTM_EnableInterrupts(DAC_TRIG, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(DAC_TRIG_IRQ);
}

void StartPlayback(uint16_t* audioData){
	FTM_StartTimer(DAC_TRIG, kFTM_SystemClock);
	// do something with audio data
}

void StopPlayback(void){
	FTM_StopTimer(DAC_TRIG);
}

void UpdateDac(uint16_t value){
	DAC_setBufferValue(AUDIO_DAC, 0u, value);
}

void DAC_TRIG_Callback(void){
	FTM_ClearStatusFlags(DAC_TRIG, kFTM_TimeOverflowFlag);
	// increment index of play back. . .
}
