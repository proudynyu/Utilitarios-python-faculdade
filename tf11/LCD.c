#include "headerDisplay.h"

// new char definition
const unsigned char bigNum[64] PROGMEM = {
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b11111111,

    0b11111111,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,

    0b11111111,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,

    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,

    0b11111111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11111111,

    0b11111111,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b11111111,

    0b11111111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    0b11111111,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b11111111,
};

// num matrix
const unsigned char nr_grande[10][4] PROGMEM = {
    {0x01, 0x02, 0x4C, 0x00},   // N0
    {0x20, 0x7C, 0x20, 0x7C},   // N1
    {0x04, 0x05, 0x4C, 0x5F},   // N2
    {0x06, 0x05, 0x5F, 0x00},   // N3
    {0x4C, 0x00, 0x20, 0x03},   // N4
    {0x07, 0x04, 0x5F, 0x00},   // N5
    {0x07, 0x04, 0x4C, 0x00},   // N6
    {0x06, 0x02, 0x20, 0x03},   // N7
    {0x07, 0x05, 0x4C, 0x00},   // N8
    {0x07, 0x05, 0x20, 0x03}    // N9
};

// Init LCD and clear the screen
void initLCD() {
  // RS == 0
  // RW == 0
  clr_bit(CONTROL, RS);
  _delay_us(15);

  DISPLAY = 0x38;

  PULSO();
  _delay_us(200);

  PULSO();
  PULSO();

  setLCD(OFF, 0);     // off LCD
  setLCD(CLEAR, 0);   // clear screen
  setLCD(ON, 0);      // on LCD
  setLCD(FLINE, 0);   // start of the cursor
};

// Set the display to receive instruction or char
void setLCD(unsigned char LCD, char instruction) {
  DISPLAY = LCD;

  // Pin RS 0 (instruction) or 1 (char)
  if (instruction == 0)
    clr_bit(CONTROL, RS);
  else
    set_bit(CONTROL, RS);

  // Enable
  PULSO();

  // delay read
  if (instruction == 0 && LCD < 4) _delay_us(2);
};

// creation of new char from bigNum variable
void newChar() {
    unsigned char j = 0, inicialPos = 0x40;

    for (unsigned char i = 0; i < 8; i ++) {
        setLCD(inicialPos, 0);

        for (unsigned char k = 0; k < 7; k++) {
            setLCD(pgm_read_bytes(&bigNum[k+j], 1));
        }

        setLCD(0x00, 1);

        j += 7;
        inicialPos += 8;
    }
};

// write in LCD screen the new Big numbers created
void writeBig(unsigned char cursor, unsigned char num) {
    setLCD(cursor, 0);
    setLCD(pgm_read_bytes(&nr_grande[num][0]), 1);
    setLCD(pgm_read_bytes(&nr_grande[num][1]), 1);
    setLCD(cursor + 64, 0);
    setLCD(pgm_read_bytes(&nr_grande[num][2]), 1);
    setLCD(pgm_read_bytes(&nr_grande[num][3]), 1);
};