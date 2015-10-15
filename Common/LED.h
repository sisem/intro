/*
 * LED.h
 *
 *  Created on: 25.09.2015
 *      Author: SEM
 */

#ifndef SOURCES_COMMON_LED_H_
#define SOURCES_COMMON_LED_H_


#include "Platform.h"
#include "WAIT1.h"

#if PL_NOF_LEDS >= 2
#include "LED1.h"
#include "LED2.h"
#endifb
#if PL_NOF_LEDS == 3
#include "LED3.h"
#endif

void LED_Test(void);

#endif /* SOURCES_COMMON_LED_H_ */
