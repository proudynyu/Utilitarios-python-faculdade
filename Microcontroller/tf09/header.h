// This libraries just works in Atmel for some reason
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CPU frequency
#define F_CPU 16000000

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

void delay(int seconds) {
	clock_t start_time = clock();
	
	while(clock() < start_time + seconds);
}
