/*
 * HeaderLCD.h
 *
 * Created: 18/05/2020 12:09:12
 *  Author: Igor
 */ 


#ifndef HEADERLCD_H_
#define HEADERLCD_H_

#include "LiquidScreen.h"

void writeLCD(unsigned char c, char instruction) {
	DISPLAY = c;
	
	if (instruction == 0) clr_bit(CONTROL, RS);
	else set_bit(CONTROL, RS);
	
	pulso();
	
	if (instruction == 0 && c < 4) _delay_ms(2);
}

void initLCD() {
	clr_bit(CONTROL, RS);
	_delay_ms(10);
	
	DISPLAY = 0x38;
	
	pulso();
	_delay_ms(200);
	
	pulso();
	pulso();
	
	writeLCD(OFF, 0);
	writeLCD(CLEAR, 0);
	writeLCD(ON, 0);
	writeLCD(0x8F, 0);
	
}

#endif /* HEADERLCD_H_ */