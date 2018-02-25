/*
 * VoiceAssigner.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */
#include "VoiceAssigner.h"
uint8_t ActiveKeys[Voice_Num] = {0};
uint16_t ClockDivisor[Voice_Num] = {0};
uint16_t Iterator[Voice_Num] = {0};
bool TriggerStep[Voice_Num] = {0};
// create different way for incrementing voices


void BeginVoiceAssigner(void){
	Init_KeyboardMatrix(ActiveKeys);
	Init_MasterClock();
}

void MasterFTM_Handler(void) {
	FTM_ClearStatusFlags(MasterFTM, kFTM_TimeOverflowFlag);

	// Trigger sequences of audio to move through data if keys are active
	for(uint8_t i = 0; i < Voice_Num; i++){
		if(ActiveKeys[i]){
			Iterator[i]++;
			if(Iterator[i] == ClockDivisor[i]){
				TriggerStep[i] = true;
				Iterator[i] = 0;
			}
		}
	}
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
	// generate divisor for the master clock for each note
	// this can be centered at the center key or be based on first key pressed after recording
	ClockDivisor[index] = DetermineDivisor(ActiveKeys[index]);
}

uint16_t DetermineDivisor(uint8_t keyIndex){

	// will replace the 32 with variable if the centering of keyboard is variable
	uint8_t position = 32 - keyIndex;
	uint8_t octaveDown = floor(position / 12);
	position %= 12;

	// Start in highest octave and work down 32 - 8 kHz
	if(octaveDown == 0){
		return 24 + (position * 2);
	}
	else if (octaveDown == 1){
		return 48 + (position * 8);
	}
	//  if(octaveDown == 2) the lowest it can go
	else{
		return 96 + (position * 16);
	}
}

void EndGate(uint8_t index){
	// close out the clock divisor
	ClockDivisor[index] = 0;
}
