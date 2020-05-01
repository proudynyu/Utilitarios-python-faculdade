#ifndef _headerDisplay_h_
#define _headerDisplay_h_

// This libraries just works in Atmel for some reason
#include <avr/io.h>
#include <avr/pgmspace.h>

// CPU frequency
#define F_CPU 16000000
#include <util/delay.h>

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

// Barramento de dados 8bits
#define DISPLAY PORTD

// Controll
#define CONTROL PORTB
#define RS      PB0
#define E       PB1

// Pulso de Enable
#define PULSO() _delay_us(1); set_bit(CONTROL, E); _delay_us(1); clr_bit(CONTROL, E); _delay_us(45)

// Constants LCD Controller
#define ON      0x0C
#define OFF     0x08
#define CLEAR   0x01
#define FLINE 	0x80

// Button definition
#define BUTTON PB2

// LCD.c functions definitions
extern void newChar();
extern void setLCD(unsigned char LCD, char instruction);
extern void initLCD();
extern void writeLCD(char *c);
extern char passwordChecker(unsigned char *pass, unsigned char *userDigit);

#endif