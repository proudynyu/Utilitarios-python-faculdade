/*
 ************************************************   
 *                                              *
 *   Author: Igor Becker                        *               
 *   Date:   23/05/2020                         *
 *   Github: https://github.com/proudynyu       *
<<<<<<< HEAD
 *   Title:  main.c                             *
=======
 *   Title:  main.c								*
>>>>>>> fca608b6ccea969b03ca6c3ab5c5557907f93d6c
 *                                              *
 ************************************************
*/

#include "header.h"

<<<<<<< HEAD
void setup() {
    // you can user pinMode(unsigned char pin, unsigned char mode)
}

int main(void) {

}
=======
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
>>>>>>> fca608b6ccea969b03ca6c3ab5c5557907f93d6c
