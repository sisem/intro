/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#include "Application.h"
#include "CLS1.h"

static bool isRunning = FALSE;

/**
 * Initializes application and starts to handle events.
 */
void APP_Start(void) {

	// initialize
	PL_Init();
	EVNT_Init();

	// start application loop
	isRunning = TRUE;
	EVNT_SetEvent(EVNT_STARTUP);
	while(isRunning) {
		//LED_Test();
		APP_Update();
	}

	// deinitialize
	PL_Deinit();
	for (;;);
}

/**
 * Requests a stop of application.
 */
void APP_Stop(void) {
	isRunning = FALSE;
}

/**
 * Called in an endless loop if applciation is running;
 */
void APP_Update(void) {
	for (;;) {
		#if PL_CONFIG_HAS_EVENTS
		EVNT_HandleEvent(APP_HandleEvent);
		#endif
		#if PL_CONFIG_HAS_KEYS
		KEY_Scan();
		#endif
	}
}

/**
 * Handles any type of event in application e.g. LED blinking except key inputs.
 * \param event Event to be handled.
 */
#if PL_CONFIG_HAS_EVENTS
void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
		case EVNT_STARTUP:
			#if PL_CONFIG_HAS_LED
			#if PL_CONFIG_NOF_LED>=1
			LED1_Neg();
			#if PL_CONFIG_HAS_BUZZER
			BUZ_Beep(500, 2000);
			#endif
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
		case EVNT_LED_HEARTBEAT:
			#if PL_CONFIG_NOF_LED>=1
			LED1_Neg();
			#endif
			break;
		default:
			#if PL_CONFIG_HAS_KEYS
			APP_KeyEvntHandler(event);
			#endif
			break;
	}
}

/**
 * Handles every type of key input.
 * \param event Event to be handled.
 */
#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle event) {
  switch(event) {
  #if PL_CONFIG_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
    case EVNT_SW1_LPRESSED:
    	CLS1_SendStr("SW1 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
      break;
    case EVNT_SW1_RELEASED:
    	CLS1_SendStr("SW1 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
    case EVNT_SW2_LPRESSED:
    	CLS1_SendStr("SW2 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW2_RELEASED:
    	CLS1_SendStr("SW2 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
    case EVNT_SW3_LPRESSED:
    	CLS1_SendStr("SW3 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW3_RELEASED:
    	CLS1_SendStr("SW3 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
    case EVNT_SW4_LPRESSED:
    	CLS1_SendStr("SW4 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW4_RELEASED:
    	CLS1_SendStr("SW4 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
    case EVNT_SW5_LPRESSED:
    	CLS1_SendStr("SW5 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW5_RELEASED:
    	CLS1_SendStr("SW1 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
  #if PL_CONFIG_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
    case EVNT_SW6_LPRESSED:
    	CLS1_SendStr("SW6 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW6_RELEASED:
    	CLS1_SendStr("SW1 released.\n", CLS1_GetStdio()->stdOut);
    	break;
  #endif
  #if PL_CONFIG_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
    case EVNT_SW7_LPRESSED:
    	CLS1_SendStr("SW7 pressed.\n", CLS1_GetStdio()->stdOut);
    	LED2_Neg();
    	break;
    case EVNT_SW7_RELEASED:
    	CLS1_SendStr("SW1 released.\n", CLS1_GetStdio()->stdOut);
      break;
   #endif
    default:
      break;
  }
}
#endif

#endif
