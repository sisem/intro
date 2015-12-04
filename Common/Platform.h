/*
 * Platform.h
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#include "PE_Types.h"

#define PL_CONFIG_HAS_TIMER 				1
#define PL_CONFIG_HAS_LED 					1
#define PL_CONFIG_HAS_KEYS 					1
#define PL_CONFIG_HAS_EVENTS 				1
#define PL_CONFIG_HAS_TRIGGER 				1
#define PL_CONFIG_HAS_DEBOUNCE 				1
#define PL_CONFIG_HAS_RTOS 					1
#define PL_CONFIG_EVENTS_AUTO_CLEAR 		0
#define PL_CONFIG_HAS_SHELL_QUEUE 			1
#define PL_SQUEUE_SINGLE_CHAR 				1
#define PL_CONFIG_HAS_SEMAPHORE 			0
#define PL_CONFIG_HAS_RADIO					1	//nRF
#define PL_HAS_RADIO						(PL_CONFIG_HAS_RADIO)
#define PL_CONFIG_HAS_REMOTE				0


#ifdef PL_BOARD_IS_ROBO
#define PL_CONFIG_NOF_LED         			2
#define PL_CONFIG_NOF_KEYS        			1
#define PL_CONFIG_HAS_BUZZER      			1
#define PL_CONFIG_HAS_LCD 		    		0
#define PL_CONFIG_HAS_SNAKE 	    		0
#define PL_CONFIG_HAS_SHELL       			1
#define PL_CONFIG_HAS_USB_CDC     			1
#define PL_CONFIG_HAS_BLUETOOTH   			1
#define PL_CONFIG_HAS_REFLECTANCE		 	1
#define PL_CONFIG_HAS_CONFIG_NVM 			1
#define PL_CONFIG_HAS_MOTOR       			1
#define PL_CONFIG_HAS_QUADRATURE			1
#define PL_CONFIG_HAS_QUAD_CALIBRATION 		1
#define PL_CONFIG_HAS_MCP4728		  		1
#define PL_CONFIG_HAS_MOTOR_QUAD  			1
#define PL_CONFIG_HAS_MOTOR_TACHO 			1
#define PL_CONFIG_HAS_ULTRASONIC			1
#define PL_CONFIG_HAS_DRIVE					1
#define PL_CONFIG_HAS_PID					1
#define PL_CONFIG_HAS_TURN					1
#define PL_CONFIG_HAS_LINE_FOLLOW			1
#endif

#ifdef PL_BOARD_IS_FRDM
#define PL_CONFIG_NOF_LED 		   			2
#define PL_CONFIG_NOF_KEYS 		   			7
#define PL_CONFIG_HAS_BUZZER     			0
#define PL_CONFIG_HAS_LCD 		   			0	//disable because of nRF module
#define PL_CONFIG_HAS_SNAKE 	 	 		0
#define PL_CONFIG_HAS_SHELL      			1
#define PL_CONFIG_HAS_USB_CDC    			1
#define PL_CONFIG_HAS_CONFIG_NVM 			0
#define PL_CONFIG_HAS_JOYSTICK				1

#endif

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_PLATFORM_H_ */
