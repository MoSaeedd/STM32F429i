/*******************************************************************************
 * @file    dma.c
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

/* Includes */
#include "dma.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup dma
 * @brief
 * @{
 */

/**
 * @defgroup dma_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_private_functions
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
void DMA2_Stream0_Init()
{
  /* Enable DMA clock in RCC */
  RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

  /* Make sure that the DMA2 stream 0 is disabled */
  if(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream0->CR))
  {
    /* DMA 2 stream 0 is enabled, shall be disabled first */
    DMA2_Stream0->CR &= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream0->CR))
    {
      /* Do nothing until EN bit is cleared */
    }
  }
  else
  {
    /* Do nothing, stream is not enabled */
  }

  /* Select the DMA channel CHSEL[2:0] in the DMA_SxCR.
   * (not needed when M->M). */

  /* Select stream priority very high */
  DMA2_Stream0->CR |= DMA_SxCR_PL;

  /* Select the data transfer direction memory to memory */
  DMA2_Stream0->CR |= DMA_SxCR_DIR_1;

  /* Select memory and peripherals sizes */
  DMA2_Stream0->CR |= DMA_SxCR_MSIZE_1;
  DMA2_Stream0->CR |= DMA_SxCR_PSIZE_1;

  /* Select FIFO mode, it will be also set by hardware when stream enabled */
  DMA2_Stream0->FCR |= DMA_SxFCR_DMDIS;

  /* Select FIFO threshold level half FIFO */
  DMA2_Stream0->FCR |= DMA_SxFCR_FTH_0;

  /* Select peripheral and memory incremented mode */
  DMA2_Stream0->CR |= DMA_SxCR_PINC;
  DMA2_Stream0->CR |= DMA_SxCR_MINC;

  /* Enable DMA transfer complete interrupt */
  DMA2_Stream0->CR |= DMA_SxCR_TCIE;

}

/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream0_Set_Addresses(const uint32_t * src,
    uint32_t * dst, const uint32_t size)
{
  /* Set the source address to the peripheral port */
  DMA2_Stream0->PAR = (uint32_t)src;

  /* Set the destination address to the memory port */
  DMA2_Stream0->M0AR = (uint32_t)dst;

  /* Set number of data items */
  DMA2_Stream0->NDTR = size;
}

/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream0_Enable()
{
  /* Clear all interrupt flags */
  DMA2->LIFCR = (DMA_LIFCR_CFEIF0 | DMA_LIFCR_CDMEIF0 | DMA_LIFCR_CTEIF0
      | DMA_LIFCR_CHTIF0 | DMA_LIFCR_CTCIF0);

  /* Enable DMA 2 stream 0 */
  DMA2_Stream0->CR |= DMA_SxCR_EN;
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
