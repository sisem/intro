/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Application.h"

void APP_Start(void) {

	PL_Init();
	EVNT_Init();

	for(;;) {
		//LED_Test();
		EVNT_HandleEvent(APP_HandleEvent);
	}

	PL_Deinit();
	for (;;) {
	}
}

void APP_HandleEvent(EVNT_Handle event) {
	switch(event) {
		case EVNT_LED_HEARTBEAT:
			LED2_Neg();
			break;
	}
}

