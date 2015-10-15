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

void APP_Start(void);
void APP_HandleEvent(EVNT_Handle);
void APP_KeyEvntHandler(EVNT_Handle);
void App(void);


void APP_Stop(void);
void APP_Update(void);

#if PL_CONFIG_HAS_EVENTS
void APP_HandleEvent(EVNT_Handle);

#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle);
#endif
#endif

#endif /* SOURCES_COMMON_APPLICATION_H_ */
