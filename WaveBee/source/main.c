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
#define SYNC_CLKSRC (CLOCK_GetFreq(kCLOCK_BusClk)/4)

#define forever for(;;)

bool sync = false;
Voice* voices;
uint32_t RecordLength = 0;

void InitFTM(void);

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    InitFTM();
    InitButtons();
    BeginAudioController();

  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    StateInstance state = GetControlState();
    uint32_t VoiceIndexes[state.voiceNumber];
    memset(VoiceIndexes, 0, state.voiceNumber);
    BeginVoiceAssigner(state.voiceNumber);
	uint16_t summedAudio;
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
			case NOT_RECORDING:
				// dont do anything
				break;
    	}

    	// all of the logic for the keyboard input and output is synchronized to the update rate of DAC
    	if(sync){
    		// check to see if key states have changed
    		// increment all of the voice indexes
    		// update the dac
    		voices = RefreshVoices();
    		summedAudio = 0;
    		for(uint8_t i = 0; i < state.voiceNumber; i++){
    			if(voices[i].isActive){
    				if(VoiceIndexes[i] > RecordLength)
    					VoiceIndexes[i] = 0;
    				VoiceIndexes[i] += voices[i].shiftValue;
    				voices[i].shiftValue = 0;
    				summedAudio += GetAudioData(VoiceIndexes[i]);
    			}
    			else
    				VoiceIndexes[i] = 0;
    		}
    		UpdateDac(summedAudio >> 4);
    	}
    }

    return 0 ;
}

// everything is synchronized to this clock
void InitFTM(void){
	ftm_config_t ftmConfig;
	FTM_GetDefaultConfig(&ftmConfig);
	ftmConfig.prescale = kFTM_Prescale_Divide_4;
	FTM_Init(SYNC_CLOCK, &ftmConfig);
	FTM_SetTimerPeriod(SYNC_CLOCK, USEC_TO_COUNT(63u, SYNC_CLKSRC));
	FTM_EnableInterrupts(SYNC_CLOCK, kFTM_TimeOverflowInterruptEnable);
	EnableIRQ(SYNC_CLOCK_IRQ);
	FTM_StartTimer(SYNC_CLOCK, kFTM_SystemClock);
}

void SYNC_CLOCK_CALLBACK(void){
	FTM_ClearStatusFlags(DAC_TRIG, kFTM_TimeOverflowFlag);
	sync = true;
}
