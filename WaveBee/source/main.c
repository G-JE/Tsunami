/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    WaveBee.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "arm_math.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_sysmpu.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"
#include "Audio\AudioController.h"
#include "Scanner\VoiceAssigner.h"
#include "Scanner\ControlState.h"
#include "DataStructures\Structures.h"
#include "Audio\PitchShift.h"

#define SYNC_CLOCK_IRQ FTM0_IRQn
#define SYNC_CLOCK FTM0
#define SYNC_CLOCK_CALLBACK FTM0_IRQHandler
#define SYNC_CLKSRC (CLOCK_GetFreq(kCLOCK_BusClk))
#define RAMP_SIZE 100u

#define forever for(;;)

bool sync = false;
Voice* voices;
uint32_t RecordLength = 0;
uint32_t startIndex, endIndex;
uint32_t playbackLength = 0;
uint16_t summedAudio = 0;
float Ramp[RAMP_SIZE];

void InitFTM(void);

int main(void) {

  	/* Init board hardware. */
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    InitFTM();
    InitControls();
    BeginAudioController();
    InitPitchShifting();

    StateInstance state = GetControlState();
    uint32_t VoiceIndexes[state.voiceNumber];
    memset(VoiceIndexes, 0, state.voiceNumber);
    memset(VoiceIndexes, 100, state.voiceNumber);
    BeginVoiceAssigner(state.voiceNumber);

	FTM_StartTimer(SYNC_CLOCK, kFTM_SystemClock);

	// generate lookup table for ramp
	for(uint16_t i = 0; i < RAMP_SIZE; i++)
		Ramp[i] = (float) (1.0 + (float) i) / (float) RAMP_SIZE;
    uint16_t scanDelay = 0;
    bool timeMode = true;
    forever {
    	// check to see if there are any changes to the control state
    	state = GetControlState();

    	// as the control inputs increase so will this switch statement for handling different functions
    	switch(state.state){
			// update the state based on a change in the control board
			case RECORDING:
				// record audio from the microphone
				RecordLength = StartRecording();
				uint16_t* audio = GetAudio();
				ShiftPitch(audio, 1);
				break;
			case UPDATE_INDEXES:
				// both the start position and length are held on a scale of 1-100
				startIndex = (float) ( RecordLength * GetPosition() ) / 100;
				endIndex = startIndex + ((RecordLength - startIndex) * GetLength() / 100);
				if(startIndex - endIndex < 200){
					if(startIndex > RecordLength - 200)
						startIndex -= 250;
					if(endIndex < 200)
						endIndex += 250;
				}
				UpdateControlState(NOP);
				break;
			case PITCH_SHIFT_MODE:
				// change the output to be controlled through time independent pitch shift mode
				timeMode = false;
			case TIME_SHIFT_MODE:
				// change the output to be controlled by changing time domain of sample
				timeMode = true;
			case NOP:
				// don't do anything
				break;
			default:
				break;
    	}

    	if(!scanDelay){
    		UpdateActiveKeys();
    		UpdateADCValues();
    	}

    	// all of the logic for the keyboard input and output is synchronized to the update rate of DAC
    	if(sync){
    		// check to see if key states have changed
    		// increment all of the voice indexes
    		// update the dac
    		voices = RefreshVoices();
    		summedAudio = 0;
    		if(timeMode){
				for(uint8_t i = 0; i < state.voiceNumber; i++){
					if(voices[i].gate){
						VoiceIndexes[i] += voices[i].shiftValue;
						if(VoiceIndexes[i] < (RAMP_SIZE + startIndex))
							summedAudio += GetAudioData(VoiceIndexes[i]) * Ramp[VoiceIndexes[i]];

						else if(VoiceIndexes[i] > endIndex - RAMP_SIZE){
							voices[i].closing += voices[i].shiftValue;
							if(voices[i].closing == RAMP_SIZE){
								voices[i].isClosing = false;
								voices[i].gate = false;
								voices[i].position = 0;
							}
							else if(voices[i].closing < RAMP_SIZE)
								summedAudio += GetAudioData(VoiceIndexes[i]) * Ramp[RAMP_SIZE - voices[i].closing];
						}
						else
							summedAudio += GetAudioData(VoiceIndexes[i]);
					}
					else if(voices[i].isClosing && !voices[i].gate){
						voices[i].closing += voices[i].shiftValue;
						if(voices[i].closing == RAMP_SIZE){
							voices[i].isClosing = false;
							voices[i].position = 0;
						}
						else if(voices[i].closing < RAMP_SIZE)
							summedAudio += GetAudioData(VoiceIndexes[i]) * Ramp[RAMP_SIZE - voices[i].closing];
					}
					else
						VoiceIndexes[i] = startIndex;

					voices[i].shiftValue = 0;
				}
    		}
    		else{
    			// apply the time independent pitch shift mode there (monophonic)
    		}
			UpdateDac(summedAudio >> 4);

			// update the key matrix every 10ms
			scanDelay++;
			scanDelay %= 160;
			sync = false;
    	}
    }

    return 0 ;
}

// everything is synchronized to this clock
void InitFTM(void){
	ftm_config_t ftmConfig;
	FTM_GetDefaultConfig(&ftmConfig);
	ftmConfig.prescale = kFTM_Prescale_Divide_1;
	FTM_Init(SYNC_CLOCK, &ftmConfig);

	// use this method for increasing the accuracy of the tick value to set the timer period
	uint32_t tickCount = (uint64_t)((uint64_t) 625 * CLOCK_GetFreq(kCLOCK_BusClk) / 10000000U);
	FTM_SetTimerPeriod(SYNC_CLOCK,  tickCount);
	FTM_EnableInterrupts(SYNC_CLOCK, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(SYNC_CLOCK_IRQ);
}

void SYNC_CLOCK_CALLBACK(void){
	FTM_ClearStatusFlags(DAC_TRIG, kFTM_TimeOverflowFlag);
	sync = true;
}
