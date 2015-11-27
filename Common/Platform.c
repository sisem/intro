/*
 * Platform.c
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */


#include "Platform.h"
#if PL_CONFIG_HAS_LED
  #include "LED.h"
#endif
#if PL_CONFIG_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_CONFIG_HAS_LCD
  #include "PDC1.h"
#endif
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_CONFIG_HAS_TIMER
  #include "Timer.h"
#endif
#if PL_CONFIG_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
  #include "Trigger.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
  #include "Debounce.h"
  #include "KeyDebounce.h"
#endif
#if PL_CONFIG_HAS_RTOS
  #include "RTOS.h"
#endif
#if PL_CONFIG_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_CONFIG_HAS_SNAKE
  #include "Snake.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
	  #include "ShellQueue.h"
	#endif
#if PL_HAS_CONFIG_SEMAPHORE
  #include "Sem.h"
#endif
#if PL_CONFIG_HAS_REFLECTANCE
  #include "Reflectance.h"
#endif
#if PL_CONFIG_HAS_MOTOR
  #include "Motor.h"
#endif
#if PL_CONFIG_HAS_DRIVE
  #include "Drive.h"
#endif
#if PL_CONFIG_HAS_CONFIG_NVM
  #include "NVM_Config.h"
#endif
#if PL_CONFIG_HAS_MCP4728
 #include "MCP4728.h"
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
  #include "Tacho.h"
#endif
#if PL_CONFIG_HAS_ULTRASONIC
  #include "Ultrasonic.h"
#endif
#if PL_CONFIG_HAS_PID
  #include "PID.h"
#endif
#if PL_CONFIG_HAS_TURN
  #include "Turn.h"
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
  #include "LineFollow.h"
#endif

void PL_Init(void) {

#if PL_CONFIG_HAS_EVENTS
	EVNT_Init();
#endif

#if PL_CONFIG_NOF_LED >=1
	LED1_Off();
#endif
#if PL_CONFIG_NOF_LED >=2
	LED2_Off();
#endif
#if PL_CONFIG_NOF_LED >=3
	LED3_Off();
#endif

#if PL_CONFIG_HAS_LEDS
	LED_Init();
#endif

#if PL_CONFIG_HAS_KEYS
	KEY_Init();
#endif

#if PL_CONFIG_HAS_DEBOUNCE
	DBNC_Init();
	KEYDBNC_Init();
#endif

#if PL_CONFIG_HAS_RTOS
	RTOS_Init();
#endif

#if PL_CONFIG_HAS_TRIGGER
	TRG_Init();
#endif

	// buzzer on startup
#if PL_CONFIG_HAS_BUZZER
	BUZ_Init();
	BUZ_Beep(500, 200);
#endif

#if PL_CONFIG_HAS_LCD
	PDC1_Init();
#endif

#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
#endif

#if PL_CONFIG_HAS_SHELL
	SHELL_Init();
#endif

#if PL_CONFIG_HAS_SHELL_QUEUE
	SQUEUE_Init();
#endif

#if PL_CONFIG_HAS_SNAKE
	SNAKE_Init();
#endif

#if PL_CONFIG_HAS_SEMAPHORE
	SEM_Init();
#endif

#if PL_CONFIG_HAS_REFLECTANCE
	REF_Init();
#endif

#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
#endif

#if PL_CONFIG_HAS_CONFIG_NVM
	NVMC_Init();
#endif

#if PL_CONFIG_HAS_MOTOR_TACHO
	TACHO_Init();
#endif

#if PL_CONFIG_HAS_ULTRASONIC
	US_Init();
#endif

#if PL_CONFIG_HAS_DRIVE
  DRV_Init();
#endif

#if PL_CONFIG_HAS_PID
	PID_Init();
#endif

#if PL_CONFIG_HAS_TURN
	TURN_Init();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
	LF_Init();
#endif

}

/* Platform.c */
void PL_Deinit(void) {
	//...
	//SCI_Deinit();
	//LED_Init();
}
