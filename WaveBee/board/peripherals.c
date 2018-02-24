/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v1.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Included files
 ******************************************************************************/
#include <Audio/AudioStreamer.h>
#include <Audio/AudioOut.h>
#include <Scanner/KeyMatrix.h>
#include "peripherals.h"

/*******************************************************************************
 * BOARD_InitBootPeripherals function
 ******************************************************************************/
void BOARD_InitBootPeripherals(void)
{
	Init_Dialog7212();
	Init_Dac();
	Init_Ftm();
	Init_KeyboardMatrix();
	Init_Buttons();
}
