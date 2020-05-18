#include "HeaderLCD.h"

const unsigned char msg[] PROGMEM = "*";

int main(void) {
	DDRD = 0xFF;
	DDRB = 0xFF;
	UCSR0B = 0x00;
	
	initLCD();
	
    while (1) {
		unsigned char count = 0x8F;
	
		for (count; count >= 0x80; count--) {
			writeLCD(count, 0);
			writeLCD(pgm_read_byte(&msg), 1);
			_delay_ms(200);
			writeLCD(CLEAR, 0);
		}
		
		for (count + 1; count < 0x8F; count++) {
			writeLCD(count, 0);
			writeLCD(pgm_read_byte(&msg), 1);
			_delay_ms(200);
			writeLCD(CLEAR, 0);
		}
    }
}

