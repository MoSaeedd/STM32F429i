/*******************************************************************************
 * @file    SysTick.h
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    21.03.2018
 *
 * @brief   SysTick configuration header file
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

/* Define to prevent recursive inclusion */
#ifndef __INC_SYSTICK_H_
#define __INC_SYSTICK_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup SysTick
 * @{
 */

/**
 * @defgroup SysTick_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_functions
 * @{
 */

/**
 * @brief   Increment SysTick counter callback
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_IncrementTicks_cb(void);

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void);

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms);

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void);

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_SYSTICK_H_ */
