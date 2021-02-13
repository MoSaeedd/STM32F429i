/*******************************************************************************
 * @file    nvic.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    31.03.2018
 *          
 * @brief   NVIC examples
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
#include "nvic.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup nvic
 * @brief
 * @{
 */

/**
 * @defgroup nvic_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_exported_functions
 * @{
 */

/**
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   None
 * @retval  None
 */
void NVIC_Init(void)
{
  /* Set priority group to 3
   * bits[3:0] are the sub-priority,
   * bits[7:4] are the pre-empt priority (0-15) */
  NVIC_SetPriorityGrouping(3);

  /* Set priority levels */
  NVIC_SetPriority(SysTick_IRQn, 0);
  NVIC_SetPriority(EXTI0_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream0_IRQn, 1);

  /* Enable interrupts at NVIC */
  NVIC_EnableIRQ(EXTI0_IRQn);
  NVIC_EnableIRQ(DMA2_Stream0_IRQn);
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
