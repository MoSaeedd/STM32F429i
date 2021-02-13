/*******************************************************************************
 * @file    dma.h
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    22.04.2018
 *
 * @brief   DMA examples
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
#ifndef __INC_DMA_H_
#define __INC_DMA_H_

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
 * @addtogroup dma
 * @{
 */

/**
 * @defgroup dma_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_functions
 * @{
 */

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream0_Init();

/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream0_Set_Addresses(const uint32_t * src,
    uint32_t * dst, const uint32_t size);

/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream0_Enable();

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

#endif /*__INC_DMA_H_ */
