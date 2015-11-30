/*
 * Application.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#define PL_HAS_RTOS_TRACE (1)

#include "Application.h"

#if PL_CONFIG_HAS_LED
#include "LED.h"
#if PL_CONFIG_NOF_LED >=1
#include "LED1.h"
#endif
#if PL_CONFIG_NOF_LED >=2
#include "LED2.h"
#endif
#endif
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#endif
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#include "BUZ1.h"
#endif
#if PL_CONFIG_HAS_SHELL
#include "Shell.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#endif
#if PL_CONFIG_HAS_ULTRASONIC
#include "Ultrasonic.h"
#endif
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#endif
#if PL_CONFIG_HAS_KEYS
#include "Keys.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
#include "Debounce.h"
#include "KeyDebounce.h"
#endif
#include "CLS1.h"

static bool isRunning = FALSE;

/**
 * Initializes application and starts to handle events.
 */
void APP_Start(void) {

	// Initialize Platform
	PL_Init();

	// start scheduler
	RTOS_Run();

	// Wait forever, we don't want to Deinit!
	for(;;);

// deinitialize
	PL_Deinit();
	for(;;);
}

/**
 * Requests a stop of application.
 */
void APP_Stop(void) {
	isRunning = FALSE;
}

/**
 * Called in an endless loop if application is running;
 */
void APP_Update(void) {
#if PL_CONFIG_HAS_EVENTS
#if PL_CONFIG_EVENTS_AUTO_CLEAR
		EVNT_HandleEvent(APP_HandleEvent, TRUE);
#else
		EVNT_HandleEvent(APP_HandleEvent, FALSE);
#endif
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
#if !PL_CONFIG_EVENTS_AUTO_CLEAR
		EVNT_ClearEvent(event);
#endif
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
	bool handled = TRUE;

	switch (event) {
/** KEY #1 **/
#if PL_CONFIG_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW1 short pressed.\n");		//Add breaks; for all cases!
#endif
#if PL_CONFIG_HAS_BUZZER
		BUZ_Beep(500, 200);
#endif
#if PL_CONFIG_HAS_LED && (PL_CONFIG_NOF_LED >= 2)
		LED2_On();
#endif
		break;

	case EVNT_SW1_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW1 long pressed.\n");
#endif
#if PL_CONFIG_HAS_SNAKE
		EVNT_SetEvent(EVNT_SNAKE_UP);

#endif
		break;

	case EVNT_SW1_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW1 released.\n");
		LED2_Off();
#endif
		break;
#endif

/** KEY #2 **/
#if PL_CONFIG_NOF_KEYS >= 2
	case EVNT_SW2_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW2 short pressed.\n");
#endif
		break;

	case EVNT_SW2_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW2 long pressed.\n");
#endif
#if PL_CONFIG_HAS_SNAKE
		EVNT_SetEvent(EVNT_SNAKE_RIGHT);
#endif
		LED2_Neg();
		break;

	case EVNT_SW2_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW2 released.\n");
#endif
		break;
#endif

/** KEY #3 **/
#if PL_CONFIG_NOF_KEYS >= 3
	case EVNT_SW3_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW3 short pressed.\n");
#endif
		break;

	case EVNT_SW3_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW3 long pressed.\n");
#endif
#if PL_CONFIG_HAS_SNAKE
		EVNT_SetEvent(EVNT_SNAKE_DOWN);
#endif
		break;

	case EVNT_SW3_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW3 released.\n");
#endif
		break;
#endif

/** KEY #4 **/
#if PL_CONFIG_NOF_KEYS >= 4
	case EVNT_SW4_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW4 short pressed.\n");
#endif
		break;

	case EVNT_SW4_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW4 long pressed.\n");
#endif
#if PL_CONFIG_HAS_SNAKE
		EVNT_SetEvent(EVNT_SNAKE_LEFT);
#endif
		break;

	case EVNT_SW4_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW4 released.\n");
#endif
		break;
#endif

/** KEY #5 **/
#if PL_CONFIG_NOF_KEYS >= 5
	case EVNT_SW5_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW5 short pressed.\n");
#endif		break;

	case EVNT_SW5_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW5 long pressed.\n");
#endif
		break;

	case EVNT_SW5_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW5 released.\n");
#endif
		break;
#endif

/** KEY #6 **/
#if PL_CONFIG_NOF_KEYS >= 6
	case EVNT_SW6_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW6 short pressed.\n");
#endif
		break;
	case EVNT_SW6_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW6 long pressed.\n");
#endif
		break;

	case EVNT_SW6_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW6 released.\n");
#endif
		break;
#endif

/** KEY #7 **/
#if PL_CONFIG_NOF_KEYS >= 7
	case EVNT_SW7_PRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW7 short pressed.\n");
#endif
		break;

case EVNT_SW7_LPRESSED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW7 long pressed.\n");
#endif
#if PL_CONFIG_HAS_SNAKE
		EVNT_SetEvent(EVNT_SNAKE_START_PAUSE);
#endif
		break;

	case EVNT_SW7_RELEASED:
#if PL_CONFIG_HAS_SHELL
		SQUEUE_SendString("SW7 released.\n");
#endif
		break;
#endif

/** DEFAULT **/
	default:
		handled = FALSE;
		break;
	}

#if !PL_CONFIG_EVENTS_AUTO_CLEAR
	if(handled) {
		EVNT_ClearEvent(event);
	}
#endif
}
#endif
