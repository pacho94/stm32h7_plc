/**
********************************************************************************
* @file    	  plc_task.h
* @author  	  pacho
* @date    	  8/28/25
* @brief   	  description
********************************************************************************
*/ 

#ifndef PLC_TASK_H
#define PLC_TASK_H
#ifdef __cplusplus
extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void plcTask(void *params);
__attribute__((weak)) void config_init__(void);
__attribute__((weak)) void config_run__(unsigned long param);
#ifdef __cplusplus
}
#endif
#endif //PLC_TASK_H
