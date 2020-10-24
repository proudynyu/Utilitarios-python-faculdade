/*
 ************************************************   
 *                                              *
 *   Author: Igor Becker                        *               
 *   Date:   23/05/2020                         *
 *   Github: https://github.com/proudynyu       *
 *   Title:  Header definition for main.c       *
 *                                              *
 ************************************************
*/

#define F_CPU 16000000

// Library
#include <avr/io.h>
#include <util/delay.h>

// Macors
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define cpl_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

// Proto Functions
void pinMode(unsigned char pin, unsigned char mode);
void digitalRead(unsigned char pin);

// Functions definitions
void pinMode(unsigned char pin, unsigned char mode) {
    unsigned char value;
    unsigned char port;
    unsigned char ddrx;

    switch(pin) {
        case 0:
            value = PD0;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 1:
            value = PD1;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 2:
            value = PD2;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 3:
            value = PD3;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 4:
            value = PD4;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 5:
            value = PD5;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 6:
            value = PD6;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 7:
            value = PD7;
            port = PORTD;
            ddrx = DDRD;
            break;
        case 8:
            value = PB0;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 9:
            value = PB1;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 10:
            value = PB2;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 11:
            value = PB3;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 12:
            value = PB4;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 13:
            value = PB5;
            port = PORTB;
            ddrx = DDRB;
            break;
        case 'A0':
            value = PC0;
            port = PORTC;
            ddrx = DDRB;
            break;
        case 'A1':
            value = PC1;
            port = PORTC;
            ddrx = DDRC;
            break;
        case 'A2':
            value = PC2;
            port = PORTC;
            ddrx = DDRC;
            break;
        case 'A3':
            value = PC3;
            port = PORTC;
            ddrx = DDRC;
            break;
        case 'A4':
            value = PC4;
            port = PORTC;
            ddrx = DDRC;
            break;
        case 'A5':
            value = PC5;
            port = PORTC;
            ddrx = DDRC;
            break;
        default:
            break;
    }

    if (mode == 'OUTPUT'){
        set_bit(ddrx, value);
        cpl_bit(port, value);
    }
    else if (mode == 'INPUT') {
        clr_bit(ddrx, value);
        set_bit(port, value);
    }
}

char digitalRead(unsigned char pin) {
}