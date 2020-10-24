/*
 * exemplo2.c
 *
 * Created: 27/05/2020 09:13:02
 *  Author: Igor
 */ 

#include "header.h"

#define DIOD1 PD7
#define DIOD2 PD6
#define DIOD3 PD5
#define BOTT1 PC0
#define BOTT2 PC1
#define BOTT3 PC2

ISR(PCINT1_vect);

int main(void) {
	
	DDRC	= 0x00;
	PORTC	= 0xFF;
	
	DDRD	= 0xFF;
	PORTD	= 0xFF;
	UCSR0B	= 0x00;
	
	set_bit(PCICR, PCIE1);
	PCMSK1 |= 0x07;
	
	sei();
	
	while(1) {}
}

ISR(PCINT1_vect) {
	if(!tst_bit(PINC, BOTT1))
		cpl_bit(PORTD, DIOD1);
	else if (!tst_bit(PINC, BOTT2))
		cpl_bit(PORTD, DIOD2);
	else if(!tst_bit(PINC, BOTT3))
		cpl_bit(PORTD, DIOD3);
	
	_delay_ms(100);
}