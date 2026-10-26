#include "main.h"
#include "RR_Scheduler.h"
#include "systick.h"

typedef uint32_t ThreadCounter ;

ThreadCounter Thread1, Thread2, Thread3, Thread4;





int main(void) {

	OSkernelIgnite();  //OS will take control from here

	for (;;)
		;
}





void thread1_function(void) {

	Thread1 = 0;

	while (1) {
		Thread1++;
		for (int i = 0; i < 100000; i++)
			;
	}
}

void thread2_function(void) {

	Thread2 = 0;
	while (1) {

		Thread2++;
		for (int i = 0; i < 100000; i++)
			;
	}
}

void thread3_function(void) {

	Thread3 = 0;
	while (1) {
		Thread3++;
		for (int i = 0; i < 100000; i++)
			;

	}
}

void thread4_function(void) {
	Thread4 = 0;

	while (1) {
		Thread4++;
		for (int i = 0; i < 100000; i++)
			;

	}
}




