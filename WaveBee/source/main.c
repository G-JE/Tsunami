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
    forever {
    	// check to see if there are any changes to the control state
    	state = GetControlState();

    	// as the control inputs increase so will this switch statement for handling different functions
    	switch(state.state){
			// update the state based on a change in the control board
			case RECORDING:
				// record audio from the microphone
				RecordLength = StartRecording();
				break;
			case NOP:
				// don't do anything
				break;
			case UPDATE_INDEXES:
				startIndex = (double) RecordLength * GetPosition();
				endIndex = startIndex + ((double) (RecordLength - startIndex) * GetLength());

				if(startIndex - endIndex < 200){
					if(startIndex > RecordLength - 200)
						startIndex -= 250;
					if(endIndex < 200)
						endIndex += 250;
				}
				break;
				// add cases for handling the encoder states
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
    		for(uint8_t i = 0; i < state.voiceNumber; i++){
    			if(voices[i].gate){
    				VoiceIndexes[i] += voices[i].shiftValue;
    				if(VoiceIndexes[i] < RAMP_SIZE)
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
