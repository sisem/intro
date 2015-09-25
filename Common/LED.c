/*
 * LED.c
 *
 *  Created on: 25.09.2015
 *      Author: SEM
 */

#include "LED.h"

void LED_Test(void) {

#if PL_NOF_LEDS >= 2
	LED1_Neg();
	WAIT1_Waitms(200);
	LED2_Neg();
	WAIT1_Waitms(200);
#endif
#if PL_NOF_LEDS == 3
	LED3_Neg();
	WAIT1_Waitms(200);
#endif

}
