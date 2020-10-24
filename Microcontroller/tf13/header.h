/*
 * header.h
 *
 * Created: 27/05/2020 09:59:47
 *  Author: Igor
 */ 


#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define cpl_bit(y, bit_x) (y ^= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define BOT1	PC0
#define BOT2	PC1
#define BOT3	PC2
#define BOT4	PC3
#define LED		PB5

#endif /* HEADER_H_ */