/*
 * Header.h
 *
 * Created: 20/05/2020 19:43:05
 *  Author: Igor
 */ 

#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000

// Library
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
<<<<<<< HEAD
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

// Barramento de dados 8bits
#define DISPLAY PORTD

#define NIBBLE  1

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
extern void writeFlash(char *c);
extern char passwordChecker(unsigned char *pass, unsigned char *userDigit);

#endif
=======
#define cpl_bit(y, bit_x) (y^=~(1<<bitX))
#define tst_bit(y, bit_x) (y &(1<<bit_x))

#define DADOS_LCD  PORTD
#define nibble_dados 1
#define CONTR_LCD  PORTB
#define RS         PB0
#define E          PB1
#define back_light PB2

#define LINHA	PINC
#define COLUNA	PORTD

// Enable LCD
#define pulso_enable(); _delay_us(1); set_bit(CONTR_LCD,E); _delay_us(1); clr_bit(CONTR_LCD,E); _delay_us(45)

// Functions prototype
void cmd_LCD(unsigned char c,char cd);
void inic_LCD_4bits();
void escreve_LCD(char *c);
void escreve_LCD_Flash(const unsigned char *c);
unsigned char ler_teclado();

#endif /* HEADER_H_ */
>>>>>>> fca608b6ccea969b03ca6c3ab5c5557907f93d6c
