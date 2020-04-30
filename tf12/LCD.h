#ifndef _LCD_H_
#define _LCD_H_

#include "headerDisplay.h"

// Set the display to receive instruction or char
void setLCD(unsigned char LCD, char instruction) {
	DISPLAY = LCD;

	// Pin RS 0 (instruction) or 1 (char)
	if (instruction == 0) clr_bit(CONTROL, RS);
	else set_bit(CONTROL, RS);

	// Enable
	PULSO();

	// delay read
	if (instruction == 0 && LCD < 4) _delay_us(2);
};

// Init LCD and clear the screen
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

	setLCD(OFF, 0);     // off LCD
	setLCD(CLEAR, 0);   // clear screen
	setLCD(ON, 0);      // on LCD
	setLCD(FLINE, 0);   // start of the cursor
};


#endif /* LCD_H_ */