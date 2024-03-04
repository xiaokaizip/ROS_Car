/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MPU6050_task.h"
#include "analog.h"
#include "balance_task.h"
#include "data_task.h"
#include "led_task.h"
#include "oled_task.h"

#include "stdio.h"

#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define F2T(X) ((unsigned int)((configTICK_RATE_HZ / (X))))

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IIC_SCL_Pin GPIO_PIN_10
#define IIC_SCL_GPIO_Port GPIOB
#define IIC_SDA_Pin GPIO_PIN_11
#define IIC_SDA_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_11
#define DC_GPIO_Port GPIOD
#define SPI_RST_Pin GPIO_PIN_12
#define SPI_RST_GPIO_Port GPIOD
#define SPI_SDA_Pin GPIO_PIN_13
#define SPI_SDA_GPIO_Port GPIOD
#define SPI_SCL_Pin GPIO_PIN_14
#define SPI_SCL_GPIO_Port GPIOD
#define Buzzer_Pin GPIO_PIN_8
#define Buzzer_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_3
#define KEY_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
