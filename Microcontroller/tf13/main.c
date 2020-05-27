/*
 ************************************************************
 *                                              			*
 *   Author: Igor Becker                        			*
 *   Date:   27/05/2020                         			*
 *   Github: https://github.com/proudynyu       			*
 *   Title:  main.c                             			*
 *	 Simul:	 https://www.tinkercad.com/things/fvLIvy5CTX5	*
 *                                              			*
 ************************************************************
*/

#include "header.h"

ISR(PCINT1_vect);

int main(void) {
    
	DDRC	= 0xF0;		// PC0:3 as IN
	PORTC	= 0x0F;		// pull_up PC0:PC3
	
	set_bit(DDRB, LED);		// Set DDRB:PB5 as OUT
	set_bit(PORTB, LED);	// Set PORTB:PB5
	
	set_bit(PCICR, PCIE1);	// Set PCICR:1
	PCMSK1 |= 0x0F;			// Set PCMSK1:INT8-INT11
		
	sei();
	
    while (1) {}
}

ISR(PCINT1_vect) {
	if(!tst_bit(PINC, BOT1)){
		for(int i = 0; i < 20; i++) {
			cpl_bit(PORTB, LED);
			_delay_ms(250);
		}
	}
	else if(!tst_bit(PINC, BOT2)) {
		for(int i = 0; i < 10; i++) {
			cpl_bit(PORTB, LED);
			_delay_ms(500);
		}
	}
	
	else if(!tst_bit(PINC, BOT3)) {
		for(int i = 0; i < 5; i++) {
			cpl_bit(PORTB, LED);
			_delay_ms(1000);
		}
	}
	else if(!tst_bit(PINC, BOT4)) {
		for(int i = 0; i < 5; i++) {
			cpl_bit(PORTB, LED);
			_delay_ms(1250);
		}
	}
}

