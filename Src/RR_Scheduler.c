/*
 * RR_Scheduler.c
 *
 *  Created on: 22-Oct-2026
 *      Author: falah
 */
#include "RR_Scheduler.h"
#include "fault_analyzer.h"
#include "systick.h"

static uint32_t threads_psp[MAX_THREADS] = { T1_STACK_START, T2_STACK_START,
		T3_STACK_START, T4_STACK_START };
static uint32_t thread_functions[MAX_THREADS];
static uint32_t current_thread = 0;



__attribute__((naked)) void init_scheduler_stack(
		uint32_t scheduler_stack_start) {

	__asm volatile ("MSR MSP, %0" : : "r" (scheduler_stack_start):);
	__asm volatile ("BX LR");

}

void init_thread_functions(void)
{
	thread_functions[0] = (uint32_t) thread1_function;
	thread_functions[1] = (uint32_t) thread2_function;
	thread_functions[2] = (uint32_t) thread3_function;
	thread_functions[3] = (uint32_t) thread4_function;


}


void init_threads_stack(void) {


	uint32_t *pPSP;

	for (int i = 0; i < MAX_THREADS; i++) {

		pPSP = (uint32_t*) threads_psp[i];
		pPSP--;
		*pPSP = 0x01000000U;
		pPSP--;
		*pPSP = thread_functions[i];
		pPSP--;
		*pPSP = 0xFFFFFFFD;


		for (int j = 0; j < 13; j++) {
			pPSP--;
			*pPSP = 0;



		}
		threads_psp[i] = (uint32_t)pPSP;
	}
}

uint32_t get_current_psp(void){
	return threads_psp[current_thread];
}


__attribute__((naked)) void SP_TO_PSP(void) {
	__asm volatile("PUSH {LR}");
	__asm volatile("BL get_current_psp");
	__asm volatile("MSR PSP, R0");
	__asm volatile("POP {LR}");

	__asm volatile("MOV R0, #0x02");
	__asm volatile("MSR CONTROL, R0");
	__asm volatile("BX LR");
}

void save_psp_value(uint32_t current_psp)
{
threads_psp[current_thread] = current_psp;
}


void next_thread(void)
{
current_thread++;
current_thread = current_thread % 4;

}

void OSkernelIgnite(void){

	init_fault_analyzer();
	init_scheduler_stack(SCHEDULER_STACK_START);
	init_thread_functions();
	init_threads_stack();
	systick_init(EXC_FREQ);
	SP_TO_PSP();

	thread1_function();
}

