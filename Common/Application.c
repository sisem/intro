/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Platform.h"
#include "LED.h"
#include "Event.h"

void APP_Start(void) {

	PL_Init();
	EVNT_Init();


	for(;;) {
		LED_Test();
	}

	PL_Deinit();
	for (;;) {
	}
}

