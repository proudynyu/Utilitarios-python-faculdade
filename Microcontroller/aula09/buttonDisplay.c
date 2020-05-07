#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define BUTTON PB2

const unsigned char NUM[] PROGMEM = {
  0x3f, 0x06, 0x5b, 0x4f,
  0x66, 0x6d, 0x7d, 0x07,
  0x7f, 0x67, 0x77, 0x7c,
  0x39, 0x5e, 0x79, 0x71
};

int main(void){
  DDRD = 0xFF;
  int count;

  clr_bit(DDRB, BUTTON);
  set_bit(PORTB, BUTTON);

  while(1){
    count = 0;
    
    do {
      if (!tst_bit(PINB, BUTTON)){
        while(!tst_bit(PINB, BUTTON));

        _delay_ms(50);

        PORTD = pgm_read_byte(&NUM[count]);
        count += 1;
      }
    }while(count < 16);
  }
}
