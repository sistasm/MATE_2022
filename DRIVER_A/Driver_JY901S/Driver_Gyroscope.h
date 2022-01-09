/**
  ******************************************************************************
  * @file           : Driver_Gyroscope.h
  * @brief          : Driver_Gyroscope.c 头文件.
  *                   本文件定义 JY901S 模块驱动的外部接口.
  ******************************************************************************
  * @revision				:
	*										v1.0	:	2022.1首次发布
  *
  *	@Contributor		:	DogeYellow
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DRIVER_GYROSCOPE_H
#define DRIVER_GYROSCOPE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "bspConfig.h"

/* Exported defines ----------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/
#define GYRO_GravityRatio 9.8

/* Exported variables --------------------------------------------------------*/
extern float GYRO_AngleYawRelative ;

/* Exported macro ------------------------------------------------------------*/
#define GYRO_DATAVERIFY_PASSED 1 
#define GYRO_DATAVERIFY_FAILED 0 

/* Exported types ------------------------------------------------------------*/
typedef struct _GYRO_FloatDataTypeDef
{
	float x_Roll ;
	float y_Yaw ;
	float z_Pitch ;
	uint8_t Flag ;
}GYRO_FloatDataTypeDef ;
typedef struct _GYRO_ShortDataTypeDef
{
	short d0 ;
	short d1 ;
	short d2 ;
	short d3 ;
	uint8_t Flag ;
}GYRO_ShortDataTypeDef ;
typedef struct _GYRO_DataTypeDef 
{
	GYRO_FloatDataTypeDef Acceleration ;
	GYRO_FloatDataTypeDef Angle ;
	GYRO_FloatDataTypeDef AngularVelocity ;
	GYRO_FloatDataTypeDef Magnetic ;
	GYRO_ShortDataTypeDef Ports ;
	float Temperature ;
	short Version ;
	uint8_t Flag ;
} GYRO_DataTypeDef ;

/* Exported functions prototypes ---------------------------------------------*/
void GYRO_GetData(GYRO_DataTypeDef* GYRO_Data) ;
uint8_t GYRO_VerifyBuf(void) ;
void GYRO_ModifySettings(void) ;
void GYRO_CalibrateYawBase(GYRO_DataTypeDef* GYRO_Data) ;
void GYRO_GetRelativeYawAngle(GYRO_DataTypeDef* GYRO_Data) ;


#ifdef __cplusplus
}
#endif

#endif /* DRIVER_GYROSCOPE_H */
