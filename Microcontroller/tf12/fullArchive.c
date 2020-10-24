// This libraries just works in Atmel for some reason
#include <avr/io.h>
#include <avr/pgmspace.h>

// CPU frequency
#define F_CPU 16000000
#include <util/delay.h>

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define clp_bit(y, bit_x) (y ^= (1<<bit_x))
#define tst_bit(y, bit_x) (y & (1<<bit_x))

// Barramento de dados 8bits
#define DISPLAY PORTD

#define NIBBLE  1

// Controll
#define CONTROL PORTB
#define RS      PB0
#define E       PB1

// Pulso de Enable
#define PULSO() _delay_us(1); set_bit(CONTROL, E); _delay_us(1); clr_bit(CONTROL, E); _delay_us(45)

// Constants LCD Controller
#define ON      0x0C
#define OFF     0x08
#define CLEAR   0x01
#define FLINE 	0x80

// Button definition
#define BUTTON PB2

// LCD.c functions definitions
void newChar();
void setLCD(unsigned char LCD, char instruction);
void initLCD();
void writeLCD(unsigned char *c);
void writeFlash(unsigned char *c);
char passwordChecker(unsigned char *pass, unsigned char *userDigit);

unsigned char msg[] = "DADOS 4BIT";

int main(void) {
    DDRD = 0xFF;
    DDRB = 0xFF;
    UCSR0B = 0xFF;

    init4bit();

    for(;;){};
}

// Set the display to receive instruction or char
void setLCD(unsigned char LCD, char instruction) {
	DISPLAY = LCD;

	// Pin RS 0 (instruction) or 1 (char)
	if (instruction == 0) clr_bit(CONTROL, RS);
	else set_bit(CONTROL, RS);

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | (0xF0 & LCD);
	else
		DISPLAY = (DISPLAY & 0x0F) | (LCD >> 4);

	// Enable
	PULSO();

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | (0xF0 & (LCD << 4));
	else
		DISPLAY = (DISPLAY & 0xF0) | (0x0F & LCD);
	
	PULSO();

	// delay read
	if (instruction == 0 && LCD < 4) _delay_us(2);
};

// Init LCD and clear the screen
void init4bit() {
	// RS == 0
	// RW == 0
	clr_bit(CONTROL, RS);
	clr_bit(CONTROL, E);
	_delay_us(15);

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | 0x30;
	else
		DISPLAY = (DISPLAY & 0xF0) | 0x03;

	PULSO();
	_delay_us(5);
	PULSO();
	_delay_us(200);
	PULSO();

	if (NIBBLE)
		DISPLAY = (DISPLAY & 0x0F) | 0x20;
	else
		DISPLAY = (DISPLAY & 0xF0) | 0x02;
	
	PULSO();

	setLCD(0x28, 0);
	setLCD(OFF, 0);     // off LCD
	setLCD(CLEAR, 0);   // clear screen
	setLCD(ON, 0);      // on LCD
	setLCD(FLINE, 0);   // start of the cursor
};

void writeLCD(unsigned char *c) {
	for(char i = 0; i < strlen(*c); i++) {
        setLCD(pgm_read_byte(&c[i]), 1);
    }
}

void writeFlash(char *c) {
	for (; pgm_read_byte(&c) != 0; c++)
		writeLCD(pgm_read_byte(c), 1);
}

char passwordChecker(unsigned char *pass, unsigned char *userDigit) {
	for (unsigned char i = 0; i < 3; i++) {
		if (pass[i] != userDigit[i]) {
			return false;
		}
	}
	return true;
}