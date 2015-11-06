/**
 * \file
 * \brief Semaphore usage
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Module using semaphores.
 */

#include "Platform.h" /* interface to the platform */
#if PL_CONFIG_HAS_SEMAPHORE
#include "FRTOS1.h"
#include "Sem.h"
#include "LED.h"

static xSemaphoreHandle sem = NULL;

static void vSlaveTask(void* pvParameters) {
	/*! \todo Implement functionality */
	for(;;) {
		if(sem != NULL) {
			if(xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE) {
				LED1_Neg();
			}
		}
	}
}

static void vMasterTask(void* pvParameters) {
	/*! \todo Implement functionality */
	for(;;) {
		if(sem != NULL) {
			(void)xSemaphoreGive(sem);
			FRTOS1_vTaskDelay(300/portTICK_RATE_MS);
		}
	}
}

void SEM_Deinit(void) {
	/* nothing */
}

/*! \brief Initializes module */
void SEM_Init(void) {
	/*! \todo Implement functionality */
	if (FRTOS1_xTaskCreate(vSlaveTask, "Slave", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
		for(;;){} /* error */
	}
	if (FRTOS1_xTaskCreate(vMasterTask, "Master", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
		for(;;){} /* error */
	}
	/* create semaphore */
	vSemaphoreCreateBinary(sem);
	if (sem == NULL) {
		for(;;); /* creation failed */
	}
}
#endif /* PL_HAS_CONFIG_SEMAPHORE */
