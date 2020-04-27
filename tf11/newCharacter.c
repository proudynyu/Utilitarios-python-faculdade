/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 25/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: New Character

	** PT-BR **
    Conte o número de vezes que um botão foi pressionado e apresente o valor (utilizando
    os números grandes vistos em aula) no LCD 16x2. O botão deve ser conectado ao pino PB2
    do ATmega.

    *********************************************************************************
*/

// End. Base: 0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78
// Cod. Char: 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07

#include "headerDisplay.h"
#include "LCD.c"

int main(void) {
    DDRD = 0xFF;
    DDRB = 0xFF;

    initLCD();

    newChar();

    while(1) {
        /* TODO */
    }

};
