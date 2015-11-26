/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"


#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#include "Trigger.h"
#include "Tacho.h"

void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  static int cntr = 0;
  #define BLINK_PERIOD_MS 500
  cntr++;

  /*
  if((cntr%(BLINK_PERIOD_MS/TMR_TICK_MS)) == 0) {
    EVNT_SetEvent(EVNT_LED_HEARTBEAT);
  }
  */
  TRG_IncTick();
  TACHO_Sample();

	// call pid
	#define PID_MS 5
	static int i = PID_MS;
	if(i-- > 0) {

		i = PID_MS;
	}
}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
