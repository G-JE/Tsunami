/*
 * Structures.h
 *
 *  Created on: Mar 4, 2018
 *      Author: ericksong
 */

#ifndef DATASTRUCTURES_STRUCTURES_H_
#define DATASTRUCTURES_STRUCTURES_H_

// struct for holding voice information
//struct {
//	float outputCoef;
//	int state;
//	float attackRate;
//	float decayRate;
//	float sustainLevel;
//	float releaseRate;
//	float targetRatioA;
//	float targetRatioDR;
//	float attackBase;
//	float decayBase;
//	float releaseBase;
//	uint32_t sampleLength;
//} typedef Envelope;


struct {
	bool gate;
	uint8_t shiftValue;
	uint8_t position;
	float hopHoldValue;
	float carryOver;
	uint8_t holding;
	uint16_t closing;
	bool isClosing;
} typedef Voice;

struct {
	float startPosition;
	float length;

} typedef AnalogInputs;

struct {
	uint8_t mode;
	uint8_t state;
	uint8_t voiceNumber;
} typedef StateInstance;

#endif /* DATASTRUCTURES_STRUCTURES_H_ */
