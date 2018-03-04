/*
 * VoiceAssigner.h
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */

#ifndef SCANNER_VOICEASSIGNER_H_
#define SCANNER_VOICEASSIGNER_H_

#include "fsl_pit.h"
#include "fsl_debug_console.h"
#include "KeyMatrix.h"
#include "math.h"
#include "Audio/AudioController.h"

#define LOG2(x) log10(x)/log10(2)
#define VOICE_NUM 4u
#define BASE_FREQ (float) 16000.0

void BeginVoiceAssigner(void);
void BuildDynamicIndex(void);
uint8_t* UpdateVoices(void);
void UpdateActiveKeys(void);
int GetNewIndex(uint8_t position);

#endif /* SCANNER_VOICEASSIGNER_H_ */
