#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

int main(void){
  DDRD = 0xFE;
  DDRB = 0x03;

  while(1){
    for(int i = 1; i < 8; i++){
      clp_bit(PORTD, i);
      _delay_ms(500);
    }

    for(int j = 0; j < 3; j++) {
      clp_bit(PORTB, j);
      _delay_ms(500);
    }
  }
}
