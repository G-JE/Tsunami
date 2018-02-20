/*
 * SD.h
 *
 *  Created on: Feb 19, 2018
 *      Author: ericksong
 */

#ifndef MEMORY_SD_H_
#define MEMORY_SD_H_

#include "fsl_sd.h"
#include "ff.h"
#include "diskio.h"

status_t Init_SD(void);
void WriteToSD(void);
void ReadFromSD(void);
status_t sdcardWaitCardInsert(void);

#endif /* MEMORY_SD_H_ */
