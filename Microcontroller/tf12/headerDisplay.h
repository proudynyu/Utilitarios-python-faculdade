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