/*
    *********************************************************************************

    Author: Igor Becker
    Github: https://github.com/proudynyu
    Date: 22/05/2020
    Class: Eletric Engineering - Microprocessor and Microcontroller
    Title: Password Checker

    *********************************************************************************
*/

const unsigned char msg1[] PROGMEM = "Insert Password\0";
const unsigned char msg2[] PROGMEM = "Key: \0";
const unsigned char comp[] PROGMEM = "Comparing...\0";
const unsigned char pass[] PROGMEM = "Success!\0";
const unsigned char erro[] PROGMEM = "Not right :/\0";

int main() {
  	unsigned char nr[4] = {};
  	unsigned char position = 0xC8;
  	unsigned char answer = 1;
  	unsigned char password[4] = "123";
  
	DDRD = 0xFF;   // PORTD e PORTB como saida
  	PORTD = 0X0F;
  	
	DDRB = 0xFF;
  	PORTB = 0x00;
  
	DDRC = 0x00;  // define o PORTC vomo entrada
  	PORTC = 0xFF;
  
  	UCSR0B = 0x00;
	
	inic_LCD_4bits();   // inicia o LCD
	escreve_LCD_Flash(msg1);
  	cmd_LCD(0xC0, 0);
    escreve_LCD_Flash(msg2);
  
	while(1) {
      	
      	do {
        	nr[0] = ler_teclado();
			
          	if (nr[0] != 0xFF){
              	cmd_LCD(position, 0);
         		cmd_LCD(nr[0], 1);
          		break;
            }
        } while(1);
      
      	_delay_ms(150);
      
      	do {
        	nr[1] = ler_teclado();
          	
          	if (nr[1] != 0xFF){
              	cmd_LCD(position+1, 0);
         		cmd_LCD(nr[1], 1);
          		break;
            }
        } while(1);

      	_delay_ms(150);
      
      	do {
        	nr[2] = ler_teclado();
          	
          	if (nr[2] != 0xFF){
              	cmd_LCD(position+2, 0);
         		cmd_LCD(nr[2], 1);
          		break;
            }
        } while(1);
      
      _delay_ms(1000);
      
	  answer = memcmp(password, nr, 3);
      if (answer == 0) {
        inic_LCD_4bits();
      	escreve_LCD_Flash(pass);
      	_delay_ms(1000);
        
        inic_LCD_4bits();   // inicia o LCD
		escreve_LCD_Flash(msg1);
  		cmd_LCD(0xC0, 0);
    	escreve_LCD_Flash(msg2);
      }
      else {
        inic_LCD_4bits();
        escreve_LCD_Flash(erro);
        _delay_ms(1000);
      	inic_LCD_4bits();   // inicia o LCD
		escreve_LCD_Flash(msg1);
  		cmd_LCD(0xC0, 0);
    	escreve_LCD_Flash(msg2);
      }
    }			
}