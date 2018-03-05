/*
 * VoiceAssigner.h
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */

#ifndef SCANNER_VOICEASSIGNER_H_
#define SCANNER_VOICEASSIGNER_H_

#include <stdlib.h>
#include "fsl_pit.h"
#include "fsl_debug_console.h"
#include "KeyMatrix.h"
#include "math.h"
#include "Audio/AudioController.h"
#include "DataStructures/Structures.h"

#define LOG2(x) log10(x)/log10(2)
#define BASE_FREQ (float) 16000.0
#define OCTAVES 4u
#define SEMITONES 12U

void BeginVoiceAssigner(uint8_t voiceNumber);
void BuildDynamicLUT(void);
Voice* RefreshVoices(void);
void UpdateActiveKeys(void);
void GetNewShiftValue(uint8_t index);

#endif /* SCANNER_VOICEASSIGNER_H_ */
