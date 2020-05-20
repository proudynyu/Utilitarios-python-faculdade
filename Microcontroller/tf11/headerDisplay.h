/*
 * HeaderLCD.h
 *
 * Created: 20/05/2020 14:26:27
 *  Author: Igor
 */ 

#ifndef HEADERLCD_H_
#define HEADERLCD_H_

#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define CONTROL PORTB
#define DISPLAY PORTD

#define RS	PB1
#define E	PB0

#define BUTTON	PB4

#define pulso() set_bit(CONTROL, E); _delay_ms(1); clp_bit(CONTROL, E); _delay_ms(45);

#define CLEAR	0X01
#define OFF		0x08
#define ON		0X0C

void initLCD();
void createChar();
void writeChar(unsigned char begining, unsigned char num);
void writeLCD(unsigned char c, unsigned char instruction);

#endif /* HEADERLCD_H_ */