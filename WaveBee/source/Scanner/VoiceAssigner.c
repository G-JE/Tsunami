/*
 * VoiceAssigner.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */
#include "VoiceAssigner.h"
// create different way for incrementing voices

uint8_t Level1[48];
uint8_t Level2[48];
uint8_t Level3[48];
uint8_t OctaveOffset[48];
uint32_t PreviousKeyState = 0;
uint8_t ActiveKeys[VOICE_NUM] = {0};

void BeginVoiceAssigner(void){
	InitKeyboardMatrix();
	BuildDynamicIndex();
}

// used to build out a lookup table that can used for generating the frequencies for four octaves
void BuildDynamicIndex(void){
	float newFreq = 0;
	float octaveOffset = 0;
	float indexFactor = 0.0;
	for(uint8_t i = 0; i < 48; i++){
		// lower two octaves
		if(i < 25)	{
			float scaler = powf((float) 2.0, (float)(12 - (24 - i))/12) / (float) 2.0;
			newFreq = BASE_FREQ * scaler;
			octaveOffset = floorf((BASE_FREQ / newFreq) - (float) 1.0);
			OctaveOffset[i] = octaveOffset;
			if(((int) newFreq % 4000)){
				indexFactor = powf(((BASE_FREQ / (octaveOffset + ((float) 1.0))) - newFreq)/(BASE_FREQ), (float) -1.0);
			}else{
				indexFactor = 0;
			}
			Level1[i] = (int) (indexFactor);
			Level2[i] = ((int)(indexFactor * 10)) % 10;
			Level3[i] = ((int) (indexFactor * 100)) % 10;
		}
		else	{
			float scaler = powf((float) 2.0, (float)(12 + (i - 24))/12) / (float) 2.0;
			newFreq = BASE_FREQ * scaler;
			octaveOffset = floorf((newFreq / BASE_FREQ) - (float) 1.0);
			if(((int) newFreq % 4000)){
				indexFactor = powf((newFreq - (BASE_FREQ * (octaveOffset + ((float) 1.0))))/(BASE_FREQ), (float) -1.0);
			}else{
				indexFactor = 0;
			}
			Level1[i] = (int) (indexFactor);
			Level2[i] = ((int)(indexFactor * 10)) % 10;
			Level3[i] = ((int) (indexFactor * 100)) % 10;
		}
	}
}

uint8_t RefreshVoices(void){
	return 1;
}

void StartVoice(void){

}

void EndVoice(uint8_t index){

}

// check the keyboard matrix for new key events
void UpdateActiveKeys(void){
	uint32_t CurrentKeyState = ScanKeys();
	uint32_t ChangedKeyState = CurrentKeyState ^ PreviousKeyState;

	// If there is a change in state update the active keys
	if(ChangedKeyState){
		// loop for opening or closing the gate for a particular key
		for(uint8_t i = 0; i < VOICE_NUM; i++){
			// if the key is active check if it is still active
			if(ActiveKeys[i]){
				if(!(CurrentKeyState & (1 << (ActiveKeys[i]-1)))){
					// end the audio stream
					ActiveKeys[i] = 0;
					EndVoice(i);
				}
			}
			else{
				// check each key to see if it active
				for(uint8_t j = 0; j < 32; j++){
					// if the key has changed to active add it to the active keys and open gate
					if((CurrentKeyState & (1 << j)) & (ChangedKeyState & (1 << j))){
						bool duplicate = false;
						for(uint8_t k = 0; k < VOICE_NUM; k++)
							duplicate |= (ActiveKeys[k] == (j+1));
						if(!duplicate){
							ActiveKeys[i] = j + 1;
							StartVoice();
						}
					}
				}
			}
		}
	}
	PreviousKeyState = CurrentKeyState;
}
