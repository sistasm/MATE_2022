/**
  ******************************************************************************
  * @file           : Driver_Remote.h
  * @brief          : Driver_Remote.c 头文件
  *                   本文件定义遥控器驱动的外部接口.
  ******************************************************************************
  * @revision				:
	*										v1.0	:	2022.1首次发布
  *
  *	@Contributor		:	DogeYellow
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DRIVER_REMOTE_H
#define DRIVER_REMOTE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "bspConfig.h"

/* Exported defines -----------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/
#define REMO_DATA_LENGTH 18

/* Exported macro ------------------------------------------------------------*/
#define REMO_DATAVERIFY_PASSED 1 
#define REMO_DATAVERIFY_FAILED 0 

/* Exported types ------------------------------------------------------------*/
typedef struct _REMO_DataTypeDef 
{
	uint16_t Ch_RH ; //!< Channel 0 
	uint16_t Ch_RV ; //!< Channel 1 
	uint16_t Ch_LH ;  //!< Channel 2 
	uint16_t Ch_LV ; //!< Channel 3 
	uint8_t S_L ; //!< Switch left 
	uint8_t S_R ; //!< Switch right
	uint16_t Wh ; //!< Wheel in the left
	uint8_t Flag ;
} REMO_DataTypeDef ;

/* Exported functions prototypes ---------------------------------------------*/
void REMO_GetData(REMO_DataTypeDef* REMO_Data) ;
uint8_t REMO_VerifyBuf(void) ;


#ifdef __cplusplus
}
#endif

#endif /* DRIVER_REMOTE_H */
