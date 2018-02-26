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
bool TriggerFlag[Voice_Num] = {0};
uint32_t StreamIndex[Voice_Num] = {0};
bool pulse = false;

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

void Init_Buttons(void){
	port_pin_config_t buttonConfig = {
			/* Internal pull-up resistor is enabled */
			kPORT_PullUp,
			/* Fast slew rate is configured */
			kPORT_FastSlewRate,
			/* Passive filter is disabled */
			kPORT_PassiveFilterDisable,
			/* Open drain is disabled */
			kPORT_OpenDrainDisable,
			/* Low drive strength is configured */
			kPORT_LowDriveStrength,
			/* Pin is configured as PTA10 */
			kPORT_MuxAsGpio,
			/* Pin Control Register fields [15:0] are not locked */
			kPORT_UnlockRegister
	};
	gpio_pin_config_t inputConfig = {kGPIO_DigitalInput, 0u};
	PORT_SetPinConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, &buttonConfig);
	PORT_SetPinInterruptConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, kPORT_InterruptEitherEdge);
	EnableIRQ(RECORD_BUTTON_IRQ);
	GPIO_PinInit(RECORD_BUTTON_GPIO, RECORD_BUTTON_PIN, &inputConfig);
}

void BeginAudioController(void){
	BeginVoiceAssigner(TriggerFlag, &pulse);
	Init_Buttons();
	Init_Dialog7212();
	Init_Dac();
	Init_Ftm();
//	uint32_t counting = 0;
	// pass audio data register to the DAC to continually publish new voltage at 16kHz
	StartPlayback(&audioData);

	// forever loop for handling all audio streams in and out
	while(1){

		// when recording is triggered start a record session, overwriting previous sample
		if(recording)
			RecordingLength = StartRecording(&recording);
		else{
			if(pulse){
				UpdateTriggers();
				RefreshVoices();
			}
			uint16_t summedAudio = 0;
			// update audio data based on note information
			for(uint8_t i = 0; i < Voice_Num; i++){
				if(TriggerFlag[i]){
					summedAudio += GetAudioData(StreamIndex[i]);
					StreamIndex[i]++;
					TriggerFlag[i] = false;
					if(StreamIndex[i] >= RecordingLength){
						StreamIndex[i] = 0;
					}
				}
				else{
					StreamIndex[i] = 0;
				}
			}
			audioData = summedAudio;
		}

	}
}
