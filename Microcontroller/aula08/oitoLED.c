#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define cpl_bit(y, bit_x) (y ^= (1<<bit_x))

int main(void) {
  DDRD = 0xFF;

  while(1) {

    // Liga os LED da esquerda para a direita
    for (int i = 7; i >= 0; i--) {
      cpl_bit(PORTD, i);
      _delay_ms(1000);
    }

    // Desliga os LED da direita para a esquerda
    for (int i = 0; i <= 7; i++) {
      cpl_bit(PORTD, i);
      _delay_ms(1000);
    }
  }
}