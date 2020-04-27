/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 25/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: New Character

	** PT-BR **
    Conte o número de vezes que um botão foi pressionado e apresente o valor (utilizando
    os números grandes vistos em aula) no LCD 16x2. O botão deve ser conectado ao pino PB2
    do ATmega.

    *********************************************************************************
*/

// End. Base: 0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78
// Cod. Char: 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07

#include "LCD.h"

int main(void) {
    DDRD = 0xFF;
    DDRB = 0xFF;
	
	unsigned char count = 0;
	unsigned char decimal = 0;

	// Init button as IN with pull-up resistor
	clr_bit(DDRB, BUTTON);
	set_bit(PORTB, BUTTON);

    initLCD();

    newChar();
	
	_delay_ms(10);
	
	writeBig(0x85, decimal);
	writeBig(0x87, count);

    while(1) {
		
		// test if button is press
        if (!tst_bit(PINB, BUTTON)) {
			while(!tst_bit(PINB, BUTTON));
			
			_delay_ms(10);
			
			setLCD(CLEAR, 0);
					
			count += 1;
			
			if (count > 9) {
				count = 0;
				decimal += 1;
				
				if (decimal > 9) decimal = 9;
				
				writeBig(0x85, decimal);
				writeBig(0x87, count);
			}
			else {
				writeBig(0x85, decimal);
				writeBig(0x87, count);
			};
			
		};
		
    };

};
