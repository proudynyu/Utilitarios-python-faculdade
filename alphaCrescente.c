/*  
    *********************************************************************************
    
    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 18/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: alphanumeric in LED 7 display

	** PT-BR **
    Exercicio: Altere o programa para que ele faça com que o programa mostre os números
    em ordem crescente e depois em ordem descrente.

    *********************************************************************************
*/

#include "header.h"

// anodo comum
// const unsigned char anodoTable[] PROGMEM = {
// 	0xC0, 0xF9, 0xA4, 0xB0,
// 	0x99, 0x92, 0x82, 0xF8,
// 	0x80, 0x98, 0x88, 0x83,
// 	0xC6, 0xA1, 0x86, 0x8E 
// };

// catodo comum
const unsigned char catodoTable[] PROGMEM = {
	0x3F, 0x06, 0x5B, 0x4F,
	0x66, 0x6D, 0x7D, 0x07,
	0x7F, 0x67, 0x77, 0x7C,
	0x39, 0x5E, 0x79, 0x71 
};

int main(void) {

	DDRD = 0xFF;
	DISPLAY = 0x00;
	UCSR08 = 0x00;

	_delay_ms(1000);

	while(1) {
		for (int i = 0, i <= 15; i++) {
			DISPLAY = pgm_read_byte(&catodoTable[i]);
			_delay_ms(1000);
		};

		for (int i = 14, i >= 0; i--) {
			DISPLAY = pgm_read_byte(&catodoTable[i]);
			_delay_ms(1000);
		};

	}
}