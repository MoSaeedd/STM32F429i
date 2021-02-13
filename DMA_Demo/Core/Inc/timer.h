/*
 * timer.h
 *
 *  Created on: Feb 13, 2021
 *      Author: test
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


#include <stdint.h>


void Timer1_InitCounterMode(void);
void Timer1_Start(void);
void Timer1_Stop(void);
uint32_t Timer1_GetCount(void);
void Timer1_ResetCounts(void);

#endif /* INC_TIMER_H_ */
