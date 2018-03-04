/*
 * AudioController.c
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#include "AudioController.h"

uint32_t RecordingLength = 0;
uint16_t audioData = 0;
bool TriggerFlag[VOICE_NUM] = {0};
uint32_t StreamIndex[VOICE_NUM] = {0};
bool pulse = false;

// audio controller owns the codec, dac
void BeginAudioController(bool* synchronize){
	Init_Dialog7212();
	Init_Dac();
}
