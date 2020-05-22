/*
 * LCD.h
 *
 * Created: 20/05/2020 19:42:48
 *  Author: Igor
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "Header.h"

const unsigned char teclado[4][4] PROGMEM = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

void cmd_LCD(unsigned char c,char cd) {
	if(cd==0) clr_bit(CONTR_LCD,RS);
	else      set_bit(CONTR_LCD,RS);
	
	// first data nibble - MSB
	#if (nibble_dados)
		DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & c);
	#else
		DADOS_LCD = (DADOS_LCD & 0xF0) | (c>>4);
	#endif
	pulso_enable();

	// second data nibble - LSB
	#if (nibble_dados)
		DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & (c<<4));
	#else
		DADOS_LCD = (DADOS_LCD & 0xF0) | (0x0F & c );
	#endif
	pulso_enable();
	
	if((cd==0) && (c<4))  _delay_ms(2);

}

// Init LCD
void inic_LCD_4bits() {
	// recomended by the product CI HD44780 producer
	clr_bit(CONTR_LCD, RS); // 0 for instruction
	clr_bit(CONTR_LCD, E);
	_delay_ms(20);
	
	//interface 8 bits
	#if (nibble_dados)
		DADOS_LCD = (DADOS_LCD & 0x0F) | 0x30;
	#else
		DADOS_LCD = (DADOS_LCD & 0xF0) | 0x03;
	#endif
	
	
	pulso_enable();
	_delay_ms(5);
	pulso_enable();
	_delay_us(200);
	pulso_enable();
	
	
	#if (nibble_dados)
		DADOS_LCD = (DADOS_LCD & 0x0F) | 0x20;
	#else
		DADOS_LCD = (DADOS_LCD & 0xF0) | 0x02;
	#endif
	
	pulso_enable();
	
	cmd_LCD(0x28,0);
	cmd_LCD(0x08,0); // Off
	cmd_LCD(0x01,0); // Clear
	cmd_LCD(0x0C,0); // Cursor
	cmd_LCD(0x80,0); // Init Position Cursor

}

void escreve_LCD(char *c) {
	for (; *c!=0;c++)  cmd_LCD(*c,1);
}

void escreve_LCD_Flash(const unsigned char *c) {
	for (;pgm_read_byte(&(*c))!=0;c++)  cmd_LCD(pgm_read_byte(&(*c)),1);
	
}

unsigned char ler_teclado() {
	unsigned char n, j, tecla = 0xFF, linha;

	for(n = 0; n < 4; n++) {
		clr_bit(COLUNA, n);
		_delay_ms(10);

		linha = LINHA & 0b00011110;

		for(j = 1; j < 5; j++) {
			if(!tst_bit(linha, j)){
				tecla = pgm_read_byte(&teclado[j-1][n]);
			}

		}
		set_bit(COLUNA, n);
	}
	return tecla;
}

#endif /* LCD_H_ */