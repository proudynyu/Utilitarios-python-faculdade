#ifndef _TECLADO_H_
#define _TECLADO_H_

#include "LCD.h"

#define LINHA PINC
#define COLUNA PORTD

unsigned char ler_teclado();

const unsigned char teclado[4][4] PROGMEM = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

unsigned char ler_teclado() {
	unsigned char n, j, tecla = 0xFF, linha;

	for(n = 0; n < 4; n++) {
		clr_bit(COLUNA, n);
		_delay_ms(10);

		linha = LINHA & 0b00011110;

		for(j = 1; j < 5; j++) {
			if(!tst_bit(linha, j))
				tecla = pgm_read_byte(&teclado[j-1][n]);

		}
		set_bit(COLUNA, n);
	}
	return tecla;
}

#endif