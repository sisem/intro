/*
 * Platform.h
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#define PL_CONFIG_HAS_TIMER 1
#define PL_CONFIG_HAS_LEDS 1
#define PL_CONFIG_HAS_KEYS 1
#define PL_CONFIG_HAS_EVENTS 1
#define PL_CONFIG_HAS_TRIGGER 1
#define PL_CONFIG_HAS_DEBOUNCE 1
#define PL_CONFIG_HAS_RTOS 1
#define PL_CONFIG_EVENTS_AUTO_CLEAR 0
#define PL_CONFIG_HAS_SHELL_QUEUE 1


#ifdef PL_BOARD_IS_ROBO
#define PL_CONFIG_NOF_LED        2
#define PL_CONFIG_NOF_KEYS       1
#define PL_CONFIG_HAS_BUZZER     1
#define PL_CONFIG_HAS_LCD 		 0
#define PL_CONFIG_HAS_SNAKE 	 0
#define PL_CONFIG_HAS_SHELL      1
#define PL_CONFIG_HAS_USB_CDC    1
#define PL_CONFIG_HAS_BLUETOOTH  0
#endif

#ifdef PL_BOARD_IS_FRDM
#define PL_CONFIG_NOF_LED 		 2
#define PL_CONFIG_NOF_KEYS 		 7
#define PL_CONFIG_HAS_BUZZER     0
#define PL_CONFIG_HAS_LCD 		 1
#define PL_CONFIG_HAS_SNAKE 	 0
#define PL_CONFIG_HAS_SHELL      1
#define PL_CONFIG_HAS_USB_CDC    1
#define PL_CONFIG_HAS_BLUETOOTH  0
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
#if PL_CONFIG_HAS_EVENTS
#include "Event.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
#include "Trigger.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
#include "Debounce.h"
#include "KeyDebounce.h"
#endif
#if PL_CONFIG_HAS_LCD
#include "PDC1.h"
#endif
#if PL_CONFIG_HAS_SNAKE
#include "Snake.h"
#endif
#if PL_CONFIG_HAS_SHELL
#include "Shell.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#endif

void PL_Init(void);
void PL_Deinit(void);


#endif /* SOURCES_COMMON_PLATFORM_H_ */
