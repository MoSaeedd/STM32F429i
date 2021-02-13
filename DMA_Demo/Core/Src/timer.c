/*
 * timer.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Mohamed Saeed
 */

#include "timer.h"
#include "stm32f4xx.h"

void Timer1_InitCounterMode(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;  //Enable the Bus used by timer 1
	TIM1->CR1 &= ~(TIM_CR1_DIR|TIM_CR1_CMS);   // set up counter mode(reset the direction bit in Control register
	TIM1->CR1 |= TIM_CR1_ARPE;
	TIM1->ARR = 65000;  // TIM1 resets at 100K/2000--> 50 Hz  which is required by the servo motor
	TIM1->PSC = 124; //  bus speed was 12.5 Mhz --> now timer increments at 100 KHz
	TIM1->CCMR1 &= ~TIM_CCMR1_CC1S;  //Set Frozen mode for channel 1
	TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M_1 |TIM_CCMR1_OC1M_2); // Set Frozen mode
	TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M_0); // Set Frozen mode
	//	  TIM1->EGR |= TIM_EGR_UG;

}


void Timer1_Start(void)
{
	TIM1->BDTR |= TIM_BDTR_MOE;	//enable main timer
	TIM1->CR1 |= TIM_CR1_CEN;		//enable TIM1

}


void Timer1_Stop(void)
{

	TIM1->BDTR &= ~TIM_BDTR_MOE;	//enable main timer
	TIM1->CR1 &= ~TIM_CR1_CEN;		//enable TIM1

}


uint32_t Timer1_GetCount(void)
{
	return TIM1->CNT;
}


void Timer1_ResetCounts(void)
{
	TIM1->CNT=0;
}
