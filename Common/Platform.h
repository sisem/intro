/*
 * Platform.h
 *
 *  Created on: Sep 25, 2015
 *      Author: pascal
 */

#ifndef SOURCES_COMMON_PLATFORM_H_
#define SOURCES_COMMON_PLATFORM_H_

#define  PL_BOARD_IS_FRDM

#ifdef PL_BOARD_IS_FRDM
	#define PL_NOF_LEDS 3
#elif defined(PL_BOARD_IS_ROBO)
	#define PL_NOF_LEDS 2
#else
	#error „Unknown board?“
#endif



void PL_Init(void);
void PL_Deinit(void);


#endif /* SOURCES_COMMON_PLATFORM_H_ */
