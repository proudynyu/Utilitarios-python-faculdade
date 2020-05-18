/*
 * LiquidScreen.h
 *
 * Created: 18/05/2020 12:10:08
 *  Author: Igor
 */ 


#ifndef LIQUIDSCREEN_H_
#define LIQUIDSCREEN_H_


#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define pulso() set_bit(CONTROL, E); _delay_ms(1); clp_bit(CONTROL, E); _delay_ms(45);

#define RS PB1
#define E PB0

#define CONTROL PORTB
#define DISPLAY PORTD

#define OFF		0x08
#define ON		0x0C
#define CLEAR	0x01

void initLCD();
void writeLCD(unsigned char c, char instruction);

#endif /* LIQUIDSCREEN_H_ */