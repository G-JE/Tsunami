/*
 * PitchShift.h
 *
 *  Created on: Mar 30, 2018
 *      Author: ericksong
 */

#ifndef AUDIO_PITCHSHIFT_H_
#define AUDIO_PITCHSHIFT_H_

#include "stdint.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "math.h"
#include "fsl_debug_console.h"
#include "Audio/KaiserWindow.h"
#include "Audio/AudioStreamer.h"

#define WLEN (256U)

extern const float Kaiser[256];

void InitPitchShifting(void);
uint16_t* ShiftPitch(uint16_t* audio, double ratio);
void princarg(const float Phasein[128], float Phase[128]);
float rt_roundd_snf(float u);
void b_cos(float x[WLEN/2]);
int Round(float number);
void fftshift(float* array);

#endif /* AUDIO_PITCHSHIFT_H_ */
