#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

#define BT1 PB4
#define BT2 PB5

const unsigned char LEDLIST[] PROGMEM = {
  PD2, PD3, PD4, PD5,
  PD7, PB0, PB1, PB2
}

int main(void) {
  DDRD = 0xFC;
  DDRB = 0X07;

  int countR = 0;
  int countL = 7;

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

      if(countR < 5) clp_bit(PORTD, LEDLIST[countR]);
      else clp_bit(PORTB, LEDLIST[countR]);

      countR += 1;
      if(countR > 7) countR = 0;
    }
    else if (!tst_bit(PINB, BT2)) {
      while(!tst_bit(PINB, BT2));

      _delay_ms(10);

      if(countL < 5) clp_bit(PORTD, LEDLIST[countL]);
      else clp_bit(PORTB, LEDLIST[countL]);

      countL += 1;
      if(countL > 7) countL = 0;
    }
  }
}
