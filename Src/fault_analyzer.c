/*
 * fault_analyzer.c
 *
 *  Created on: 25-Oct-2026
 *      Author: falah
 */

#include "fault_analyzer.h"
#include "stdint.h"

void init_fault_analyzer(void) {
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

	*pSHCSR |= (1U << 16);
	*pSHCSR |= (1U << 17);
	*pSHCSR |= (1U << 18);

}

void HardFault_Handler(void) {

}

void MemManage_Handler(void) {

}

void BusFault_Handler(void) {

}

void UsageFault_Handler(void) {

}
