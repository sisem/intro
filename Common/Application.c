/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#define PL_HAS_RTOS_TRACE (1)
#include "Application.h"

#if PL_CONFIG_HAS_LEDS
#include "LED.h"
#if PL_CONFIG_NOF_LED >=1
#include "LED1.h"
#endif
#endif

#include "CLS1.h"

static bool isRunning = FALSE;

/**
 * Initializes application and starts to handle events.
 */
void APP_Start(void) {

	// initialize
	PL_Init();
	EVNT_Init();

	// Initialize all tasks
	RTOS_Init();
	// start scheduler
	RTOS_Run();

	// Wait forever, we don't want to Deinit!
	for (;;) {
	}

// deinitialize
	PL_Deinit();
	for (;;)
		;
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
#if PL_CONFIG_HAS_EVENTS
		EVNT_HandleEvent(APP_HandleEvent);
#endif
#if PL_CONFIG_HAS_KEYS
		//KEY_Scan();
		KEYDBNC_Process();
#endif
}


/**
 * Handles any type of event in application e.g. LED blinking except key inputs.
 * \param event Event to be handled.
 */
#if PL_CONFIG_HAS_EVENTS
void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
	case EVNT_STARTUP:
		break;
	default:
#if PL_CONFIG_HAS_KEYS
		APP_KeyEvntHandler(event);
#endif
		break;
	}
}
#endif

/**
 * Handles every type of key input.
 * \param event Event to be handled.
 */
#if PL_CONFIG_HAS_KEYS
void APP_KeyEvntHandler(EVNT_Handle event) {
	switch (event) {

#if PL_CONFIG_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
	case EVNT_SW1_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW1 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
#if PL_CONFIG_HAS_BUZZER
		BUZ_Beep(500, 200);
#endif
		LED2_On();
		break;
	case EVNT_SW1_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW1 released.\n", CLS1_GetStdio()->stdOut);
		LED2_Off();
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 2
	case EVNT_SW2_PRESSED:
	case EVNT_SW2_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW2 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW2_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW2 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 3
	case EVNT_SW3_PRESSED:
	case EVNT_SW3_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW3 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW3_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW3 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 4
	case EVNT_SW4_PRESSED:
	case EVNT_SW4_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW4 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW4_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW4 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 5
	case EVNT_SW5_PRESSED:
	case EVNT_SW5_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW5 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW5_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW5 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 6
	case EVNT_SW6_PRESSED:
	case EVNT_SW6_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW6 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW6_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW6 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif

#if PL_CONFIG_NOF_KEYS >= 7
	case EVNT_SW7_PRESSED:
	case EVNT_SW7_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW7 pressed.\n", CLS1_GetStdio()->stdOut);
#endif
		LED2_Neg();
		break;
	case EVNT_SW7_RELEASED:
#if PL_CONFIG_HAS_SHELL
		CLS1_SendStr("SW7 released.\n", CLS1_GetStdio()->stdOut);
#endif
		break;
#endif
	default:
		break;
	}
}
#endif
