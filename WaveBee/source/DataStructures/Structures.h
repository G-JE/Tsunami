/*
 * Structures.h
 *
 *  Created on: Mar 4, 2018
 *      Author: ericksong
 */

#ifndef DATASTRUCTURES_STRUCTURES_H_
#define DATASTRUCTURES_STRUCTURES_H_

// struct for holding voice information
struct {
	bool isActive;
	uint8_t shiftValue;
	uint8_t position;
	float hopHoldValue;
	float carryOver;
	uint8_t holding;
} typedef Voice;

struct {
	uint8_t mode;
	uint8_t state;
	uint8_t voiceNumber;
} typedef StateInstance;

#endif /* DATASTRUCTURES_STRUCTURES_H_ */
