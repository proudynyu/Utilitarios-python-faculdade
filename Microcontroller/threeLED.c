#include <avr/io.h>
#include <avr/pgmspace.h>

#define F_CPU 16000000
#include <util/delay.h>

#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define set_bit(y, bit_x) (y |= (1<<bit_x))

#define BT1 PB2
#define BT2 PB1
#define LED1 PD7
#define LED2 PD6
#define LED3 PD5
#define LED4 PD4
#define LED5 PD3
#define LED6 PD2

int main(void){
  DDRD = 0xFC;

  clr_bit(DDRB, BT1);
  set_bit(PORTB, BT1);

  clr_bit(DDRB, BT2);
  set_bit(PORTB, BT2);

  while(1) {
    if (!tst_bit(PINB, BT1)){
      while(!tst_bit(PINB, BT1));

      _delay_ms(10);
      clp_bit(PORTD, LED1);
      clp_bit(PORTD, LED2);
      clp_bit(PORTD, LED3);
      
    }
    else if (!tst_bit(PINB, BT2)) {
      while(!tst_bit(PINB, BT2));

      _delay_ms(10);

      clp_bit(PORTD, LED4);
      clp_bit(PORTD, LED5);
      clp_bit(PORTD, LED6);
    }

  }
}