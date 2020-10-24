#ifndef _LCD_H_
#define _LCD_H_

#include "headerDisplay.h"

// Set the display to receive instruction or char
void setLCD(unsigned char LCD, char instruction) {
	DISPLAY = LCD;

	// Pin RS 0 (instruction) or 1 (char)
	if (instruction == 0) clr_bit(CONTROL, RS);
	else set_bit(CONTROL, RS);

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | (0xF0 & LCD);
	else
		DISPLAY = (DISPLAY & 0x0F) | (LCD >> 4);

	// Enable
	PULSO();

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | (0xF0 & (LCD << 4));
	else
		DISPLAY = (DISPLAY & 0xF0) | (0x0F & LCD);
	
	PULSO();

	// delay read
	if (instruction == 0 && LCD < 4) _delay_us(2);
};

// Init LCD and clear the screen
void init4bit() {
	// RS == 0
	// RW == 0
	clr_bit(CONTROL, RS);
	clr_bit(CONTROL, E);
	_delay_us(15);

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | 0x30;
	else
		DISPLAY = (DISPLAY & 0xF0) | 0x03;

	PULSO();
	_delay_us(5);
	PULSO();
	_delay_us(200);
	PULSO();

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | 0x20;
	else
		DISPLAY = (DISPLAY & 0xF0) | 0x02;
	
	PULSO();

	setLCD(0x28, 0);
	setLCD(OFF, 0);     // off LCD
	setLCD(CLEAR, 0);   // clear screen
	setLCD(ON, 0);      // on LCD
	setLCD(FLINE, 0);   // start of the cursor
};

void writeLCD(char *c) {
	for(; *c != 0; c++) setLCD(*c, 1);
}

void writeFlash(char *c) {
	for (; pgm_read_byte(& (*c)) != 0; c++)
		writeLCD(pgm_read_byte(& (*c)), 1);
}

char passwordChecker(unsigned char *pass, unsigned char *userDigit) {
	for (unsigned char i = 0; i < 3; i++) {
		if (pass[i] != userDigit[i]) {
			return false;
		}
	}
	return true;
}

#endif /* LCD_H_ */