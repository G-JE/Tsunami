/*
 * VoiceAssigner.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */
#include "VoiceAssigner.h"
uint8_t ActiveKeys[Voice_Num] = {0};

// create different way for incrementing voices
bool voice1, voice2, voice3, voice4 = false;


void BeginVoiceAssigner(void){
	Init_KeyboardMatrix(ActiveKeys);
	Init_MasterClock();
}

void MasterFTM_Handler(void) {
	FTM_ClearStatusFlags(MasterFTM, kFTM_TimeOverflowFlag);
}

void Init_MasterClock(void){
	ftm_config_t ftmConfig;

	FTM_GetDefaultConfig(&ftmConfig);
	ftmConfig.prescale = kFTM_Prescale_Divide_1;
	FTM_Init(MasterFTM, &ftmConfig);

	// tick number is based on a value to get 786000Hz as a master clock
	FTM_SetTimerPeriod(MasterFTM, 76u);
	FTM_EnableInterrupts(MasterFTM, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(MasterFTM_IRQ);
	FTM_StartTimer(MasterFTM, kFTM_SystemClock);
}

void RefreshVoices(void){
	UpdateActiveKeys();
}

void StartGate(uint8_t index){

}

void EndGate(uint8_t index){

}
