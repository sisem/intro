/*
 * Platform.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Platform.h"

void PL_Init(void) {
#if PL_CONFIG_HAS_LEDS
	LED_Init();
#endif

	// buzzer on startup
#if PL_CONFIG_HAS_BUZZER
	BUZ_Beep(500, 200);
#endif

#if PL_CONFIG_HAS_LCD
	PDC1_Init();
#endif

#if PL_CONFIG_HAS_SNAKE
	SNAKE_Init();
#endif

	// clear leds
#if PL_CONFIG_NOF_LED >=1
	LED1_Off();
#endif
#if PL_CONFIG_NOF_LED >=2
	LED2_Off();
#endif
#if PL_CONFIG_NOF_LED >=3
	LED3_Off();
#endif

}

/* Platform.c */
void PL_Deinit(void) {
	//...
	//SCI_Deinit();
	//LED_Init();
}
