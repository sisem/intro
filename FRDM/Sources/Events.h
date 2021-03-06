/* ###################################################################
**     Filename    : Events.h
**     Project     : FRDM
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-24, 13:18, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LED1.h"
#include "LED1.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "LED2.h"
#include "LED1.h"
#include "LEDpin3.h"
#include "BitIoLdd3.h"
#include "CLS1.h"
#include "UTIL1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "UTIL1.h"
#include "BitIoLdd4.h"
#include "SW2.h"
#include "BitIoLdd5.h"
#include "SW3.h"
#include "BitIoLdd6.h"
#include "SW1.h"
#include "BitIoLdd4.h"
#include "SW2.h"
#include "BitIoLdd5.h"
#include "SW3.h"
#include "BitIoLdd6.h"
#include "SW4.h"
#include "BitIoLdd7.h"
#include "SW5.h"
#include "BitIoLdd8.h"
#include "SW6.h"
#include "BitIoLdd9.h"
#include "SW7.h"
#include "BitIoLdd10.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "FRTOS1.h"
/*#include "PDC1.h"
#include "RESpin2.h"
#include "BitIoLdd14.h"
#include "SCEpin1.h"
#include "BitIoLdd13.h"
#include "D_Cpin1.h"
#include "BitIoLdd15.h"*/
#include "USB1.h"
#include "USB0.h"
#include "CDC1.h"
#include "Tx1.h"
#include "Rx1.h"
#include "IFsh1.h"
#include "IntFlashLdd1.h"
#include "KSDK1.h"
#include "RNET1.h"
#include "RF1.h"
#include "CE1.h"
#include "BitIoLdd16.h"
#include "CSN1.h"
#include "BitIoLdd17.h"
#include "SM1.h"
#include "SMasterLdd1.h"
/*#include "SPI1.h"
#include "Clock1.h"
#include "BitIoLdd11.h"
#include "Output1.h"
#include "BitIoLdd12.h"
#include "GDisp1.h"
#include "GFONT1.h"
#include "FDisp1.h"*/
#include "CS1.h"
#include "WAIT1.h"
#include "HF1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "Platform.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


void FRTOS1_vApplicationStackOverflowHook(xTaskHandle pxTask, char *pcTaskName);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationStackOverflowHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         if enabled, this hook will be called in case of a stack
**         overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pxTask          - Task handle
**       * pcTaskName      - Pointer to task name
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationTickHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationTickHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called by the RTOS for every
**         tick increment.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationIdleHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationIdleHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called when the RTOS is idle.
**         This might be a good place to go into low power mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationMallocFailedHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationMallocFailedHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, the RTOS will call this hook in case memory
**         allocation failed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

/**
 * Called if timer interrupt 1 elapsed.
 */
void TI1_OnInterrupt(void);
