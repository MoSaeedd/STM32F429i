/*******************************************************************************
 * @file    exti.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    10.04.2018
 *          
 * @brief   EXTI examples
 * @note    
 *
@verbatim
Copyright (C) Almohandes.org, 2018

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Includes */
#include "exti.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup exti
 * @brief
 * @{
 */

/**
 * @defgroup exti_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_functions
 * @{
 */

/**
 * @brief   Push button EXTI initialization function
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_Init_PB()
{
  /* Enable SYSCFG clock */
  RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

  /* Map PA0 to EXT0 */
  SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

  /* Enable rising edge trigger */
  EXTI->RTSR |= EXTI_RTSR_TR0;

  /* Disable falling edge trigger */
  EXTI->FTSR &= ~(EXTI_FTSR_TR0);

  /* Enable interrupt line */
  EXTI->IMR |= EXTI_IMR_MR0;

  /* Enable event line */
  EXTI->EMR |= EXTI_EMR_MR0;
}

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
