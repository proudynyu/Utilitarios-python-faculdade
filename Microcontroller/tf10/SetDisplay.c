/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 24/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: Set Display

	** PT-BR **
  Elabore um programa para deslocar o caractere "*" (asterisco) no LCD, ele deve
	aparecer primeiro na posicao 0x8F e seguir para a posicao 0x80 passando por todas
	as posicoes intermediarias, ao chegar ao final da linha o caractere deve retornar
	(vai e vem).

    *********************************************************************************
*/

#include "headerDisplay.h"

void setLCD(unsigned char LCD, char instruction);
void initLCD();

const unsigned char asterisco PROGMEM = "*";

const unsigned char line1 [] PROGMEM = {
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85,
  0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B,
  0x8C, 0x8D, 0x8E, 0x8F
};

int main(void) {
  DDRD, DDRB = 0xFF;
  UCSR0B = 0x00;

  initLCD();

  while (1) {

    for (unsigned char i = 15; i >= 0; i--) {
      setLCD(pgm_read_byte(&linha1[i]), 0);
      setLCD(pgm_read_byte(&asterisco), 1);
      _delay_us(500);
      setLCD(CLEAR, 0);
      _delay_us(10);
    };

  };
  
};

void setLCD(unsigned char LCD, char instruction) {
  DISPLAY = LCD;

  // Pino RS para 0 ou 1
  if (instruction == 0)
    clr_bit(CONTROL, RS);
  else
    set_bit(CONTROL, RS);

  // Enable
  PULSO();

  // Leitura de atraso
  if (instruction == 0 && LCD < 4) _delay_us(2);
}

void initLCD() {
  // RS == 0
  // RW == 0
  clr_bit(CONTROL, RS);
  _delay_us(15);

  DISPLAY = 0x38;

  PULSO();
  _delay_us(200);

  PULSO();
  PULSO();

  setLCD(OFF, 0);     // desliga
  setLCD(CLEAR, 0);   // limpa
  setLCD(ON, 0);      // liga
}
