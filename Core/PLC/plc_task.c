/**
********************************************************************************
* @file    	  plc_task.c
* @author  	  pacho
* @date    	  8/28/25
* @brief
********************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "plc_task.h"
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <stdio.h>
#include "iec_std_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
TIME __CURRENT_TIME;
BOOL __DEBUG;
static unsigned long __tick = 0;
unsigned long long common_ticktime__ __attribute__((weak));
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/**
 * Task to execute PLC program
 * @param params
 */
void plcTask(void *params) {
    SemaphoreHandle_t mutex = (SemaphoreHandle_t) params;
    // TaskHandle_t modbus = ((struct task_parameters *)params)->modbus;

    config_init__();

    TickType_t last_tick = xTaskGetTickCount();
    TickType_t delay = (TickType_t) (common_ticktime__ / 1000000);

    const TIME ticktime = {0, common_ticktime__};

    for (;;) {
        xSemaphoreTake(mutex, portMAX_DELAY);

        // update_inputs();
        config_run__(__tick++);
        // update_ouputs();

        xSemaphoreGive(mutex);

        __CURRENT_TIME = __time_add(__CURRENT_TIME, ticktime);

#ifdef ANALOG_INPUTS
        adc_start();
#endif
        // if (MODBUS_MASTER)
        //     xTaskNotify(modbus, MODBUS_MASTER_TRIGGER, eSetBits);

        vTaskDelayUntil(&last_tick, delay / portTICK_RATE_MS);
    }
}

/**
 * PLC init function
 */
__attribute__((weak)) void config_init__(void) {
 //Do nothing include when ST is translated in C
}

/**
 * PLC program execution funtion
 */
__attribute__((weak)) void config_run__(unsigned long param) {
 //Do nothing include when ST is translated in C
}