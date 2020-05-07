#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define BT1 PB2
#define BT2 PB3

int main(void) {
  DDRD = 0xFC;

  const unsigned char LEDLIST[] = {
    PD2, PD3, PD4, PD5,
    PD6, PD7
  };

  int countR = 0;
  int countL = 5;

  // botao1
  clr_bit(DDRB, BT1);
  set_bit(PORTB, BT1);

  // botao2
  clr_bit(DDRB, BT2);
  set_bit(PORTB, BT2);

  while(1) {
    if(!tst_bit(PINB, BT1)){
      while(!tst_bit(PINB, BT1));

      _delay_ms(10);

      clp_bit(PORTD, LEDLIST[countR]);

      countR += 1;
      if(countR > 5) countR = 0;
    }
    else if (!tst_bit(PINB, BT2)) {
      while(!tst_bit(PINB, BT2));

      _delay_ms(10);

      clp_bit(PORTD, LEDLIST[countL]);

      countL -= 1;
      if(countL < 0) countL = 5;
    }
  }
}
