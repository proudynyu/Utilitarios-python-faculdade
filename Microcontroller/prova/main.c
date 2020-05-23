/*
 ************************************************   
 *                                              *
 *   Author: Igor Becker                        *               
 *   Date:   23/05/2020                         *
 *   Github: https://github.com/proudynyu       *
 *   Title:  main.c								*
 *                                              *
 ************************************************
*/

#include "header.h"

int main(void) {
    setup();
	unsigned char HIGH = dRead(13);

	while(1) {
        dWrite(13, HIGH);
        _delay_ms(1000);
        dWrite(13, !HIGH);
        _delay_ms(100);
	}
}

void setup() {
	pMode(13, 1);
}
