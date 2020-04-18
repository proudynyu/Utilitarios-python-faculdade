/*  
    *********************************************************************************
    
    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 17/04/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: SetIO in Arduino (Little framework to set IO in Arduino)

    ** PT-BR **
    Exercicio: No Atmel Studio crie uma função responsável por habilitar os pinos do
    ATmega328P como entrada ou saída. Quando o pino for uma entrada habilite o pull-up
    interno do terminal.

    *********************************************************************************
*/

#include "header.h"

// Function that sets In or Out
int ioSelect();
void portSelect(int IO);

// Main wizard
int main(void) {
    int result, option;
    
    while(1) {
        system("CLEAR");

        result = ioSelect();
        printf("\n\n");
        
        if (option == 0) {
            break;
        };

        option = portSelect(result);
        printf("\n\n");

        system("PAUSE");
        return 0;
    }
}

// Setting IO option
int ioSelect() {
    int option;
    printf("Select if the PIN will be IN or OUT: ")
    printf("\t1. In");
    print("\t2. Out");
    printf("\n\tPress 'enter' to quit")
    scanf(": %i", &option);

    if (option != 1 && option != 2) {
        option = 0;
    };

    return option;
};

// Setting PIN that receives IN or OUT
// OUT in HighLevel only
void portSelect(int IO) {
    int option;

    printf("Select what PIN in Arduino (0 to 13) to modify: ");
    scanf("option: %i", &option);

    switch (IO) {
        case 1:
            switch (option) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    print("Set DDRD pin %i as 0", &option);
                    clr_bit(DDRD, option);
                    set_bit(PORTD, option); // pull-up resistor
                    break;      
                
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                    printf("Set DDRB pin %i as 0", &option);
                    clr_bit(DDRB, option);
                    set_bit(PORTB, option); // pull-up resistor
                    break;

                default:
                    print("Wrong interaction, breaking the code");
                    break;
            }

        case 2:
            switch (option) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    print("Set DDRD pin %i as 1", &option);
                    set_bit(DDRD, option);
                    break;      
                
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                    printf("Set DDRB pin %i as 1", &option);
                    set_bit(DDRB, option);
                    break;

                default:
                    print("Wrong interaction, breaking the code");
                    break;
            }
            break;
    };
}

