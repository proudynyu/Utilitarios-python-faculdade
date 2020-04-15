#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))

int main(void) {
	set_bit(DDRB, 5);

	while(1){
		// pisca 5 vezes rapido
		for (int i = 0; i < 5; i++) {
			clp_bit(PORTB, 5);
			_delay_ms(100);
			clp_bit(PORTB, 5);
			_delay_ms(100);
		}

		// pisca 3 vezes devagar
		for (int i = 0; i < 3; i++) {
			clp_bit(PORTB, 5);
			_delay_ms(2000);
			clp_bit(PORTB, 5);
			_delay_ms(2000);
		}
	}
}