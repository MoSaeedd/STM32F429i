/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx.h"
#include "nvic.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Timer8InitCompareMode(void);
void Timer8InitSetDutyCycle(uint8_t duty);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	SystemClock_Config();
	  __enable_irq();
	  NVIC_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //enable Port C
	GPIOE->MODER &= ~GPIO_MODER_MODE9_0; // output mode (10)
	GPIOE->MODER |= GPIO_MODER_MODE9_1; // output mode (10)
//	GPIOE->OTYPER &= ~(GPIO_OTYPER_OT6); // Push-Pull mode
//	GPIOE->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR6_0 ); // high speed gpio mode
//	GPIOE->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6_1;
//	RCC->APB2ENR |=  RCC_APB2LPENR_SYSCFGLPEN; // enable the APB2 bus
//	SYSCFG->CMPCR |= SYSCFG_CMPCR_CMP_PD;
//
//	while ((SYSCFG->CMPCR & SYSCFG_CMPCR_READY)!=  SYSCFG_CMPCR_READY);

	GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPD9);
//	GPIOE->AFR[1] &= ~GPIO_AF1;
	GPIOE->AFR[1] |= GPIO_AF1_TIM1;

  Timer8InitCompareMode();
//  Timer8InitSetDutyCycle(2);


  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void Timer8InitCompareMode(void)
{
	  RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;  //Enable the Bus used by timer 8
	  TIM1->CR1 &= ~(TIM_CR1_DIR|TIM_CR1_CMS);   // set up counter mode(reset the direction bit in Control register
	  TIM1->CR1 |= TIM_CR1_ARPE;
	  TIM1->ARR = 2000;  // TIM1 resets at 100K/2000--> 50 Hz  which is required by the servo motor
	  TIM1->PSC = 124; //  bus speed was 12.5 Mhz --> now timer increments at 100 KHz
	  TIM1->CCMR1 &= ~TIM_CCMR1_CC1S;  //Set Compare mode for channel 1
	  TIM1->CCMR1 |= (TIM_CCMR1_OC1M_1 |TIM_CCMR1_OC1M_2); // Set PWM mode 1 |------______|
	  TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M_0); // Set PWM mode 1 |------______|
	  TIM1->CCER &=  ~TIM_CCER_CC1P;
	  TIM1->CCR1 =1000;
	  TIM1->EGR |= TIM_EGR_UG;
	  TIM1->CCER |=  TIM_CCER_CC1E; //enable the cc output
	  TIM1->BDTR |= TIM_BDTR_MOE;	//enable main timer
	  TIM1->CR1 |= TIM_CR1_CEN;		//enable TIM1
}

/* expects duty cycle 0-100*/

void Timer8InitSetDutyCycle(uint8_t duty)
{
	  TIM1->CCR1 =(uint32_t)((uint32_t)duty* TIM1->ARR/100);

}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
