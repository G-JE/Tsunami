/*
 * AudioOut.h
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#ifndef AUDIO_AUDIOOUT_H_
#define AUDIO_AUDIOOUT_H_

#include "fsl_dac.h"
#include "fsl_ftm.h"

#define DAC_TRIG FTM0
#define AUDIO_DAC DAC0
#define DAC_TRIG_IRQ FTM0_IRQn
#define DAC_TRIG_Callback FTM0_IRQHandler
#define TRIGGER_CLKSRC (CLOCK_GetFreq(kCLOCK_BusClk)/4)

void Init_Ftm(void);
void Init_Dac(void);
void UpdateDac(uint16_t value);
void StartPlayback(volatile uint16_t* audioData);

#endif /* AUDIO_AUDIOOUT_H_ */
