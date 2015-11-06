/**
 * \file
 * \brief Buzzer driver interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for the buzzer.
 */

#include "Platform.h"
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#include "BUZ1.h"
#include "Trigger.h"
#include "UTIL1.h"
#include "CLS1.h"

typedef struct {
  uint16_t buzPeriodTicks; /*!< number of trigger ticks for a PWM period */
  uint16_t buzIterationCntr; /*!< number of iterations */
} BUZ_TrgInfo;

static volatile BUZ_TrgInfo trgInfo;



uint8_t BUZ_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io)
{
	  if (UTIL1_strcmp((char*)cmd, CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, "BUZ1 help")==0) {
	    *handled = TRUE;
	    CLS1_SendHelpStr((unsigned char*)"BUZ", (unsigned char*)"Group of BUZ commands\r\n", io->stdOut);
	    CLS1_SendHelpStr((unsigned char*)"  beep", (unsigned char*)"Beep with 1kHz for 1 sec\r\n", io->stdOut);
	    return ERR_OK;
	  } else if (UTIL1_strcmp((char*)cmd, "BUZ beep")==0) {
		  *handled = TRUE;
		  return BUZ_Beep(1000, 1000);
	    }
  return ERR_OK;
}



static void BUZ_Toggle(void *dataPtr) {
  BUZ_TrgInfo *trgInfo = (BUZ_TrgInfo *)dataPtr;
  
  if (trgInfo->buzIterationCntr==0) {
    BUZ1_ClrVal(); /* turn buzzer off */
  } else {
    trgInfo->buzIterationCntr--;
    BUZ1_NegVal();
    (void)TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo->buzPeriodTicks, BUZ_Toggle, trgInfo);
  }
}

uint8_t BUZ_Beep(uint16_t freq, uint16_t durationMs) {
  if (trgInfo.buzIterationCntr==0) { /* only if buzzer is not running right now */
    BUZ1_SetVal(); /* turn buzzer on */
    trgInfo.buzPeriodTicks = (1000*TRG_TICKS_MS)/freq;
    trgInfo.buzIterationCntr = durationMs/TRG_TICKS_MS/trgInfo.buzPeriodTicks;
    return TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo.buzPeriodTicks, BUZ_Toggle, (void*)&trgInfo);
  } else {
    return ERR_BUSY;
  }
}

void BUZ_Deinit(void) {
  /* nothing to do */
}

void BUZ_Init(void) {
  BUZ1_SetVal(); /* turn buzzer off */
  trgInfo.buzPeriodTicks = 0;
  trgInfo.buzIterationCntr = 0;
}
#endif /* PL_CONFIG_HAS_BUZZER */
