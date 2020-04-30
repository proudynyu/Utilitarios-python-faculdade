#include "teclado.h"

const char msg1[] PROGMEM = "Teclado 4x4\0";
const char msg2[] PROGMEM = "Tecla =\0";

int main() {
	unsigned char nr;

	DDRB = 0xFF;
	PORTB = 0x00;

	DDRC = 0x00;
	PORTC = 0xFF;

	DDRD = 0xFF;
	PORTD = 0x0F;
	UCSR0B = 0x00;


	initLCD();

	escreve_LCD(msg1); // TODO
	setLCD(0xC0, 0);
	escreve_LCD(msg2); // TODO

	while(1) {
		nr = ler_teclado();

		if (nr != 0xFF) {
			setLCD(0xC8, 0);
			setLCD(nr, 1);
		}
	}
}