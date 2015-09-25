/*
 * LED.c
 *
 *  Created on: 25.09.2015
 *      Author: SEM
 */

#include "LEDR.h"
#include "LEDG.h"
#include "LEDB.h"
#include "WAIT1.h"

void LED_Test(void) {
	LEDR_Neg();
	WAIT1_Waitms(200);
	LEDG_Neg();
	WAIT1_Waitms(200);
	LEDB_Neg();
	WAIT1_Waitms(200);
}
