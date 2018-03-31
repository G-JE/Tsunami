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
#include "fsl_debug_console.h"

#define WLEN 256

void testFunctions(void);
uint16_t* ShiftPitch(uint16_t* audio, double ratio);
double PrincArg(double phaseIn);
int Round(float number);
void fftshift(uint16_t* array);

#endif /* AUDIO_PITCHSHIFT_H_ */
