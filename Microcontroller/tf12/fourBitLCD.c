#include "LCD.h";

prog_char msg[] = "DADOS 4BIT"

int main(void) {
    DDRD = 0xFF;
    DDRB = 0xFF;

    init4bit();
    escreveLCD();
    setLCD(0xC0, 0);
    escreveFlash(msg);

    for(;;){};
}