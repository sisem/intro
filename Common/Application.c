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

	for (;;) {
		//LED_Test();
		//EVNT_HandleEvent(APP_HandleEvent);
		App();
	}

	PL_Deinit();
	for (;;) {
	}
}

void App(void) {
	EVNT_SetEvent(EVNT_STARTUP);
	for (;;) {
#if PL_CONFIG_HAS_EVENTS
		EVNT_HandleEvent(APP_HandleEvent);
#endif
#if PL_CONFIG_HAS_KEYS
		KEY_Scan();
#endif
	}
}

void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
	case EVNT_STARTUP:
#if PL_CONFIG_HAS_LED
#if PL_CONFIG_NOF_LED>=1
		LED1_Neg();
#endif
		WAIT1_Waitms(50);
#if PL_CONFIG_NOF_LED>=2
		LED2_Neg();
#endif
		WAIT1_Waitms(50);
#if PL_CONFIG_NOF_LED>=3
		LED3_Neg();
#endif
		WAIT1_Waitms(50);
#endif
#if PL_CONFIG_NOF_LED>=1
		LED1_Off();
#endif
#if PL_CONFIG_NOF_LED>=2
		LED2_Off();
#endif
#if PL_CONFIG_NOF_LED>=3
		LED3_Off();
#endif
		break;

//	case EVENT_LED_HEARTBEAT:
//#if PL_CONFIG_NOF_LED>=1
//		LED1_Neg();
//#endif
		break;

	default:
#if PL_CONFIG_HAS_KEYS
		APP_KeyEvntHandler(event);
#endif
		break;
	}
}

#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle event) {
  switch(event) {
  #if PL_CONFIG_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
    case EVNT_SW1_LPRESSED:
    case EVNT_SW1_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
    case EVNT_SW2_LPRESSED:
    case EVNT_SW2_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
    case EVNT_SW3_LPRESSED:
    case EVNT_SW3_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
    case EVNT_SW4_LPRESSED:
    case EVNT_SW4_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
    case EVNT_SW5_LPRESSED:
    case EVNT_SW5_RELEASED:
      LED1_Neg();
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
    case EVNT_SW6_LPRESSED:
    case EVNT_SW6_RELEASED:
      LED1_Neg();
      break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
    case EVNT_SW7_LPRESSED:
    case EVNT_SW7_RELEASED:
      LED1_Neg();
      break;
   #endif
    default:
      break;
  }
}
#endif
