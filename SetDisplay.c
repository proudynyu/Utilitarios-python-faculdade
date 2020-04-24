/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 24/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: Set Display

	** PT-BR **
  Elabore um programa para deslocar o caractere � * � (asterisco) no LCD, ele deve
	aparecer primeiro na posi��o 0x8F e seguir para a posi��o 0x80 passando por todas
	as posi��es intermedi�rias, ao chegar ao final da linha o caractere deve retornar
	(vai e vem).

    *********************************************************************************
*/

#include "header.h"

void setLCD(unsigned char LCD, char instruction);
void writeLCD();
void initLCD();

int main(void) {
  DDRD, DDRB = 0xFF;
  UCSR0B = 0x00;

  initLCD();

  while (1) {
  }
}

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

void writeLCD(){

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
  setLCD(FLINE, 0);   // cursor na ultima posicao da Fline
}
