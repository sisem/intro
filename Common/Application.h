/*
 * Application.h
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#ifndef SOURCES_COMMON_APPLICATION_H_
#define SOURCES_COMMON_APPLICATION_H_

#include "Platform.h"
#include "Event.h"
#include "LED.h"
#include "LED1.h"
#include "LED2.h"
#include "LED3.h"

void APP_Start(void);
void APP_HandleEvent(EVNT_Handle);
void APP_KeyEvntHandler(EVNT_Handle);
void App(void);

#endif /* SOURCES_COMMON_APPLICATION_H_ */
