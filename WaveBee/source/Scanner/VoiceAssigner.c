/*
 * VoiceAssigner.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */
#include "VoiceAssigner.h"
// create different way for incrementing voices

float FrequencyCoefficients[OCTAVES * SEMITONES];
uint32_t PreviousKeyState = 0;
uint8_t VoiceNumber = 0;
Voice* Voices;


void BeginVoiceAssigner(uint8_t voiceNumber){
	VoiceNumber = voiceNumber;

	// dynamically allocate memory for the Voices
	Voices = malloc(VoiceNumber * sizeof *Voices);
	memset(Voices, 0, sizeof *Voices * voiceNumber);

	InitKeyboardMatrix();
	BuildDynamicLUT();
}

// used to build out a lookup table that can used for generating the frequencies for four octaves
void BuildDynamicLUT(void){
	float newFreq = 0;
	for(uint8_t i = 0; i < (OCTAVES * SEMITONES); i++){
		// lower two octaves
		if(i < ((OCTAVES * SEMITONES)/2 + 1))	{
			float scaler = powf((float) 2.0, (float)(12 - (24 - i))/12) / (float) 2.0;
			newFreq = BASE_FREQ * scaler;
			FrequencyCoefficients[i] = ((BASE_FREQ) - newFreq)/(newFreq);
		}
		// upper two octaves
		else{
			float scaler = powf((float) 2.0, (float)(12 + (i - 24))/12) / (float) 2.0;
			newFreq = BASE_FREQ * scaler;
			FrequencyCoefficients[i] = (newFreq - (BASE_FREQ))/(BASE_FREQ);
		}
	}
		// set center frequency to 0 since that tries to divide by zero. . .
		FrequencyCoefficients[OCTAVES*SEMITONES/2] = 0;
}

Voice* RefreshVoices(void){
	// find the new shift values for each key based on its position
	for(uint8_t i = 0; i < VoiceNumber; i++){
		if(Voices[i].gate || Voices[i].isClosing)
			GetNewShiftValue(i);
	}
	return Voices;
}

// check the keyboard matrix for new key events
void UpdateActiveKeys(void){
	uint32_t CurrentKeyState = ScanKeys();
	uint32_t ChangedKeyState = CurrentKeyState ^ PreviousKeyState;

	// If there is a change in state update the active keys
	if(ChangedKeyState){
		// loop for opening or closing the gate for a particular key
		for(uint8_t i = 0; i < VoiceNumber; i++){
			// if the key is active check if it is still active
			if(Voices[i].gate && !Voices[i].isClosing){
				if(!(CurrentKeyState & (1 << (Voices[i].position-1)))){
					// end the audio stream
					memset(&Voices[i], 0, sizeof Voices[i]);
					Voices[i].isClosing = true;
				}
			}
			else{
				// check each key to see if it active
				for(uint8_t j = 0; j < 32; j++){
					// if the key has changed to active add it to the active keys and open gate
					if((CurrentKeyState & (1 << j)) & (ChangedKeyState & (1 << j))){
						bool duplicate = false;
						for(uint8_t k = 0; k < VoiceNumber; k++)
							duplicate |= (Voices[k].position == (j+1));

						if(!duplicate){
							Voices[i].position = j + 1;
							Voices[i].gate = true;
							Voices[i].hopHoldValue = FrequencyCoefficients[8 + j + 1];
							Voices[i].closing = 0;
						}
					}
				}
			}
		}
	}
	PreviousKeyState = CurrentKeyState;
}


void GetNewShiftValue(uint8_t i){
	// the value of 42 is based on centering 16kHz at key position 16
	uint8_t position = Voices[i].position;

	// center position is key 16
	if(position < 16){
		if(Voices[i].carryOver > 1){
			Voices[i].holding += (int) Voices[i].carryOver;
			Voices[i].carryOver -= floor(Voices[i].carryOver);
		}
		if(Voices[i].holding){
			Voices[i].holding--;
		}
		else{
			Voices[i].shiftValue++;
			Voices[i].carryOver += Voices[i].hopHoldValue;
		}
	}
	else{
		Voices[i].carryOver += Voices[i].hopHoldValue;
		Voices[i].shiftValue += (int) Voices[i].carryOver;
		Voices[i].carryOver -= (float) Voices[i].shiftValue;
		Voices[i].shiftValue++;
	}
}

