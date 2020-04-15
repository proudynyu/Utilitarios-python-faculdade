#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define cpl_bit(y, bit_x) (y ^= (1<<bit_x))

int main(void) {
	set_bit(DDRB, 5);

	while(1) {
		// Liga LED
		cpl_bit(PORTB, 5);
		_delay_ms(1000);

		// Desliga LED
		cpl_bit(PORTB, 5);
		_delay_ms(500);
	}
}