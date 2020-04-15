#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define cpl_bit(y, bit_x) (y ^= (1<<bit_x))

int main(void) {
	int DDRB = 0xFF;

	while(1) {

		// Liga os LED da esquerda para a direita
		for (int i = 8; i > 0; i--) {
			cpl_bit(PORTB, i);
			_delay_ms(1000);
		}

		// Desliga os LED da direita para a esquerda
		for (int i = 0; i < 8; i++) {
			cpl_bit(PORTB, i);
			_delay_ms(1000);
		}
	}
}