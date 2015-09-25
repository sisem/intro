/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Platform.h"
#include "LED.h"

void APP_Start(void) {

	PL_Init();

	for(;;) {
		LED_Test();
	}

	PL_Deinit();
	for (;;) {
	}
}

