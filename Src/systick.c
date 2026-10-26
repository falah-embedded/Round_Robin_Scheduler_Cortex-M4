/*
 * systick.c
 *
 *  Created on: 23-Oct-2026
 *      Author: falah
 */
#include <stdint.h>
#include "systick.h"
#include "RR_Scheduler.h"

void systick_init(uint32_t freq)
{
	 uint32_t reload = (SYSTEM_CLK_SPEED/EXC_FREQ)-1;

	 uint32_t *pSRVR = (uint32_t *)0xE000E014;
	 uint32_t *pSCSR = (uint32_t *)0xE000E010;

	 *pSRVR &= ~(0x00FFFFFF);
	 *pSRVR |= reload;


	 *pSCSR |= (1<<1);
	 *pSCSR |= (1<<2);
	 *pSCSR |= (1<<0);
}




__attribute__((naked)) void SysTick_Handler(void)
{
	//SAVING THE CONTEXT OF CURRENT THREAD
__asm volatile("MRS R0, PSP");
__asm volatile("STMDB R0!, {R4-R11}");
__asm volatile("PUSH {LR}");
__asm volatile("BL save_psp_value");

//RESTORING THE CONTEXT OF NEXT TASK
__asm volatile("BL next_thread");
__asm volatile("BL get_current_psp");
__asm volatile("LDMIA R0!, {R4-R11}");
__asm volatile("MSR PSP, R0");
__asm volatile("POP {LR}");
__asm volatile("BX LR");
}



