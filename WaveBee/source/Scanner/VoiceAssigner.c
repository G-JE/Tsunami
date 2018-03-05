/*
 * VoiceAssigner.c
 *
 *  Created on: Feb 21, 2018
 *      Author: ericksong
 */
#include "VoiceAssigner.h"
// create different way for incrementing voices

uint8_t Level1[OCTAVES * SEMITONES];
uint8_t Level2[OCTAVES * SEMITONES];
uint8_t OctaveOffset[OCTAVES * SEMITONES];

uint32_t PreviousKeyState = 0;
uint8_t VoiceNumber = 0;
Voice Voices[4];

// 0 is hold index, 1+ is to skip index by value
uint16_t* VoiceCounter;

void BeginVoiceAssigner(uint8_t voiceNumber){
	VoiceCounter = malloc(voiceNumber * sizeof (uint16_t));
	VoiceNumber = voiceNumber;
	InitKeyboardMatrix();
	BuildDynamicLUT();
}

// used to build out a lookup table that can used for generating the frequencies for four octaves
void BuildDynamicLUT(void){
	float newFreq = 0;
	float octaveOffset = 0;
	float indexFactor = 0.0;
	for(uint8_t i = 0; i < (OCTAVES * SEMITONES); i++){
		// lower two octaves
		if(i < ((OCTAVES * SEMITONES)/2 + 1))	{
			float scaler = powf((float) 2.0, (float)(12 - (24 - i))/12) / (float) 2.0;
			newFreq = BASE_FREQ * scaler;
			octaveOffset = floorf((BASE_FREQ / newFreq) - (float) 1.0);
			OctaveOffset[i] = octaveOffset;
			if(((int) newFreq % 4000)){
				indexFactor = powf(((BASE_FREQ / (octaveOffset + ((float) 1.0))) - newFreq)/(BASE_FREQ), (float) -1.0);
			}else{
				indexFactor = 0;
			}
			if(indexFactor > 10){
				Level1[i] = (int) (indexFactor);
				Level2[i] = 1000 / ((int)(indexFactor * 10));
			}else{
				Level1[i] = (int) (indexFactor);
				Level2[i] = 100 / ((int)(indexFactor * 10));
			}
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
			if(indexFactor > 10){
				Level1[i] = (int) (indexFactor);
				Level2[i] = 1000 / ((int)(indexFactor * 10));
			}else{
				Level1[i] = (int) (indexFactor);
				Level2[i] = 100 / ((int)(indexFactor * 10));
			}
		}
	}
}

Voice* RefreshVoices(void){
	// scan the matrix and update all of the keys
	UpdateActiveKeys();

	// find the new shift values for each key based on its position
	for(uint8_t i = 0; i < VoiceNumber; i++){
		if(Voices[i].isActive)
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
			if(Voices[i].isActive){
				if(!(CurrentKeyState & (1 << (Voices[i].position-1)))){
					// end the audio stream
					Voices[i].isActive = false;
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
							Voices[i].isActive = true;
						}
					}
				}
			}
		}
	}
	PreviousKeyState = CurrentKeyState;
}


void GetNewShiftValue(uint8_t index){
	// the value of 42 is based on centering 16kHz at key position 16
	uint8_t position = Voices[index].position;

	// use the lookup table to determine how to match the new frequency
	uint8_t octaveOffset = OctaveOffset[42 - position];
	uint8_t level1 = Level1[42 - position];
	uint8_t level2 = Level2[42 - position];
	uint8_t wrap = level1 * level2;

	if(position < 16){
		// is above the sampling rate is down sampled and needs to hold
		// hold the shift register
		if(Voices[index].holding == 0){
			if(!(VoiceCounter[index] % level1)){
				Voices[index].shiftValue = 0;
				if(!(VoiceCounter[index] % (level2 * level1)))
					Voices[index].shiftValue++;
			}
			else
				Voices[index].shiftValue++;

			Voices[index].holding = octaveOffset;
		}
		else{
			Voices[index].holding--;
			Voices[index].shiftValue = 0;
		}
	}
	else{
		// is above the sampling rate and needs to skip values
		// increment the shift register
		Voices[index].shiftValue += octaveOffset;
		if(!(VoiceCounter[index] % level1)){
			Voices[index].shiftValue++;
			if(!(VoiceCounter[index] % (level2 * level1)))
				Voices[index].shiftValue--;
		}
		else
			Voices[index].shiftValue++;
	}

	Voices[index].counter++;

	// wrap the counter register when it reaches a point of repeating the pattern
	Voices[index].counter %= wrap;

	// reset the counter back to start index 1
	if(Voices[index].counter == 0)
		Voices[index].counter = 1;

}
