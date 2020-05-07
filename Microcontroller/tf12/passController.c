/*  
    *********************************************************************************
    
    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 30/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: Acess Control 

	** PT-BR **
    Elabore um programa para o controle de acesso por senha numérica. A senha deve conter 
	3 dígitos. Quando a senha for correta, uma saída deve ser acionada.

    *********************************************************************************
*/

#include "teclado.h"

const char msg1[] PROGMEM = "Password:\0";
const char msg2[] PROGMEM = "=\0";
const char pass[4] PROGMEM = {"1", "2", "3"};

int main() {
	unsigned char nr, checkPass[4];
	unsigned char buttonPres = 0;
	unsigned char respChecker = false; // bool

	DDRB = 0xFF;
	PORTB = 0x00;

	DDRC = 0x00;
	PORTC = 0xFF;

	DDRD = 0xFF;
	PORTD = 0x0F;
	UCSR0B = 0x00;


	initLCD();

	writeLCD(msg1);
	setLCD(0xC0, 0);
	writeLCD(msg2);

	do {
		setLCD(0xC2, 0); // set the initial position for password

		while(buttonPres != 2) {
			nr = ler_teclado();

			if (nr != 0xFF) {
				setLCD(nr, 1);
				checkPass[buttonPres] = nr; // need to fix
				buttonPres += 1;			
			}
			
		}

		respChecker = passwordChecker(*pass, *checkPass);

		setLCD(CLEAR, 0);
		setLCD(FLINE, 0);
		writeLCD("Wrong answer");
		setLCD(0xC0, 0);
		writeLCD("Try again");
		_delay_us(1000);
		
		setLCD(CLEAR, 0);

	} while (respChecker != true);
}