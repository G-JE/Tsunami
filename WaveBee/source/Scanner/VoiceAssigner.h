/*
 * VoiceAssigner.h
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */

#ifndef SCANNER_VOICEASSIGNER_H_
#define SCANNER_VOICEASSIGNER_H_

#include "fsl_ftm.h"
#include "fsl_debug_console.h"
#include "KeyMatrix.h"

#define MasterFTM FTM2
#define MasterFTM_IRQ FTM2_IRQn
#define MasterFTM_Handler FTM2_IRQHandler
#define CLK_SRC (CLOCK_GetFreq(kCLOCK_BusClk)/4)

#define Voice_Num 4u

void BeginVoiceAssigner(void);
void Init_MasterClock(void);
void CombineSounds(void);
void StartGate(void);
void EndGate(void);

#endif /* SCANNER_VOICEASSIGNER_H_ */
