/*
 * RR_Scheduler.h
 *
 *  Created on: 22-Oct-2026
 *      Author: falah
 */#include "stdint.h"

#ifndef RR_SCHEDULER_H_
#define RR_SCHEDULER_H_


#define THREAD_STACK_SIZE     1024U
#define SCHEDULER_STACK_SIZE  1024U

#define SRAM_START            0x20000000U
#define SRAM_SIZE             ((128) * (1024))
#define SRAM_END              ((SRAM_START) + (SRAM_SIZE))

#define T1_STACK_START        SRAM_END
#define T2_STACK_START        ((T1_STACK_START) - ((1) * (THREAD_STACK_SIZE)))
#define T3_STACK_START        ((T1_STACK_START) - ((2) * (THREAD_STACK_SIZE)))
#define T4_STACK_START        ((T1_STACK_START) - ((3) * (THREAD_STACK_SIZE)))
#define SCHEDULER_STACK_START ((T1_STACK_START) - ((4) * (THREAD_STACK_SIZE)))

#define MAX_THREADS             4


void thread1_function(void);
void thread2_function(void);
void thread3_function(void);
void thread4_function(void);

__attribute__((naked)) void init_scheduler_stack(uint32_t scheduler_stack_start);
void init_threads_stack(void);
uint32_t get_current_psp(void);
void save_psp_value(uint32_t current_psp);
void next_thread(void);

void OSkernelIgnite(void);

#endif /* RR_SCHEDULER_H_ */
