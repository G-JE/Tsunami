/*
 * AudioController.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "AudioController.h"

uint32_t RecordingLength = 0;
bool recording = false;
uint16_t audioData = 0;
bool TriggerFlag[VOICE_NUM] = {0};
uint32_t StreamIndex[VOICE_NUM] = {0};
bool pulse = false;
//bool UpdateDacPulse = false;


void RECORD_BUTTON_HANDLER(void){
	GPIO_PortClearInterruptFlags(RECORD_BUTTON_GPIO, (1U << RECORD_BUTTON_PIN));

	//Trigger the recording to start and end based on rising or falling edge
	if(!recording){
		recording = true;
		printf("recording\r\n");
	}
	else{
		recording = false;
		printf("stopped recording\r\n");
	}
	// this is needed for M4 ARM arch
    __DSB();
}

// audio controller owns the codec, dac
void BeginAudioController(bool* synchronize){
	Init_Dialog7212();
	Init_Dac();
}
