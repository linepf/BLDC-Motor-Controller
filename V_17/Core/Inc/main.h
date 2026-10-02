/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "user_main.h"
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW_2_Pin GPIO_PIN_4
#define SW_2_GPIO_Port GPIOE
#define SW_2_EXTI_IRQn EXTI4_IRQn
#define DC_Pin GPIO_PIN_5
#define DC_GPIO_Port GPIOE
#define RESET_Pin GPIO_PIN_6
#define RESET_GPIO_Port GPIOE
#define CS_Pin GPIO_PIN_8
#define CS_GPIO_Port GPIOF
#define LED_Pin GPIO_PIN_9
#define LED_GPIO_Port GPIOF
#define HALL_A_Pin GPIO_PIN_3
#define HALL_A_GPIO_Port GPIOC
#define HALL_A_EXTI_IRQn EXTI3_IRQn
#define BEMF_V_Pin GPIO_PIN_12
#define BEMF_V_GPIO_Port GPIOF
#define BEMF_V_EXTI_IRQn EXTI15_10_IRQn
#define SW_1_Pin GPIO_PIN_0
#define SW_1_GPIO_Port GPIOG
#define Buzzer_Pin GPIO_PIN_10
#define Buzzer_GPIO_Port GPIOE
#define SW_3_Pin GPIO_PIN_15
#define SW_3_GPIO_Port GPIOE
#define DT_Pin GPIO_PIN_10
#define DT_GPIO_Port GPIOB
#define DT_EXTI_IRQn EXTI15_10_IRQn
#define CLK_Pin GPIO_PIN_11
#define CLK_GPIO_Port GPIOB
#define BEMF_W_Pin GPIO_PIN_14
#define BEMF_W_GPIO_Port GPIOD
#define BEMF_W_EXTI_IRQn EXTI15_10_IRQn
#define BEMF_U_Pin GPIO_PIN_15
#define BEMF_U_GPIO_Port GPIOD
#define BEMF_U_EXTI_IRQn EXTI15_10_IRQn
#define HALL_B_Pin GPIO_PIN_0
#define HALL_B_GPIO_Port GPIOD
#define HALL_B_EXTI_IRQn EXTI0_IRQn
#define CALL_C_Pin GPIO_PIN_1
#define CALL_C_GPIO_Port GPIOD
#define CALL_C_EXTI_IRQn EXTI1_IRQn
#define LCD_CLEAR_Pin GPIO_PIN_0
#define LCD_CLEAR_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
