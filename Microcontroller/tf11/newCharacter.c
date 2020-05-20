/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 20/05/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: PressCharacter

	** PT-BR **
    Conte o número de vezes que um botão foi pressionado e apresente o valor (utilizando
    os números grandes vistos em aula) no LCD 16x2. O botão deve ser conectado ao pino PB2
    do ATmega.

    *********************************************************************************
*/

#include "LCD.h"

const unsigned char msg[] PROGMEM = "Press: ";

int main(void) {
	DDRD = 0xFF;
	DDRB = 0x03;
	UCSR0B = 0x00;
	
	clr_bit(DDRB, BUTTON);
	set_bit(PORTB, BUTTON);
	
	unsigned char count = 0;
	
	initLCD();
	
	createChar();
	
	
	while (1) {
		writeLCD(0x80, 0);
		for (char i = 0; i < 6; i++) {
			writeLCD(pgm_read_byte(&msg[i]), 1);
		}
		
		if(!tst_bit(PINB, BUTTON)){
			while(!tst_bit(PINB, BUTTON));
			count = count == 9 ? 0 : (count + 1);
		}
		writeChar(0x87, count);
	}
}


