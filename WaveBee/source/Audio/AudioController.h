/*
 * AudioController.h
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#ifndef AUDIO_AUDIOCONTROLLER_H_
#define AUDIO_AUDIOCONTROLLER_H_

#include "AudioStreamer.h"
#include "AudioOut.h"
#include "fsl_debug_console.h"
#include "Scanner/VoiceAssigner.h"

#define RECORD_BUTTON_PIN 8u
#define RECORD_BUTTON_PORT PORTA
#define RECORD_BUTTON_GPIO GPIOA
#define RECORD_BUTTON_HANDLER PORTA_IRQHandler
#define RECORD_BUTTON_IRQ PORTA_IRQn

void Init_Buttons(void);
void BeginAudioController(void);

#endif /* AUDIO_AUDIOCONTROLLER_H_ */
