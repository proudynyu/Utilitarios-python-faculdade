// This libraries just works in Atmel for some reason
#include <avr/io.h>
#include <utils/delay>
#include <stdio.h>
#include <stdlib.h>

// CPU frequency
#define F_CPU 16000000

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x)) 
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))
