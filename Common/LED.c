/*
 * LED.c
 *
 *  Created on: 25.09.2015
 *      Author: SEM
 */

#if PL_CONFIG_HAS_LEDS
#include "LED.h"
#if PL_CONFIG_NOF_LED >= 2
#include "LED1.h"
#endif
#endif

#include "Trigger.h"

#if PL_CONFIG_NOF_LED >= 1
static void LED_HeartBeat(void *p) {
	(void)p;
	LED1_Neg();
	TRG_SetTrigger(TRG_LED_BLINK, 1000/TRG_TICKS_MS, LED_HeartBeat, NULL);
}
#endif
