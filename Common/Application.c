/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Platform.h"

void APP_Start(void) {

	PL_Init();

	PL_Deinit();
	for (;;)
		;
}

