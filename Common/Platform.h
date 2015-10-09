/*
 * Platform.h
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#define PL_CONFIG_HAS_EVENTS 1
#define PL_CONFIG_HAS_TIMER 1
#define PL_CONFIG_HAS_LEDS 1

#ifdef PL_BOARD_IS_ROBO
#define PL_NOF_LEDS 2
#define PL_CONFIG_HAS_KEYS 0 // 1
#define PL_CONFIG_NOF_KEYS 0 // 2
#endif

#ifdef PL_BOARD_IS_FRDM
#define PL_NOF_LEDS 3
#define PL_CONFIG_HAS_KEYS 0 // 1
#define PL_CONFIG_NOF_KEYS 0 // 7
#endif

#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#endif
#if PL_CONFIG_HAS_LEDS
#include "LED.h"
#endif
#if PL_CONFIG_HAS_KEYS
#include "Keys.h"
#endif

void PL_Init(void);
void PL_Deinit(void);


#endif /* SOURCES_COMMON_PLATFORM_H_ */
