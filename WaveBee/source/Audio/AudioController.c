/*
 * AudioController.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "AudioController.h"

uint32_t RecordingLength = 0;
uint16_t audioData = 0;


// audio controller owns the codec, dac
void BeginAudioController(void){
	Init_Dialog7212();
	Init_Dac();
}
