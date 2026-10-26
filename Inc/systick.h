/*
 * systick.h
 *
 *  Created on: 23-Oct-2026
 *      Author: falah
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


#define SYSTEM_CLK_SPEED    16000000U
#define EXC_FREQ     1000U

void systick_init(uint32_t freq);


#endif /* SYSTICK_H_ */
