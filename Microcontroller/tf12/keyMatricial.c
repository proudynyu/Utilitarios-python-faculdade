#define F_CPU 16000000

// Bibliotecas
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// Macros
#define set_bit(y, bit_x) (y |= (1<<bit_x))
#define clr_bit(y, bit_x) (y &= ~(1<<bit_x))
#define cpl_bit(y, bit_x) (y^=~(1<<bitX))
#define tst_bit(y, bit_x) (y &(1<<bit_x))


// Definições para facilitar a troca dos pinos do hardware e facilitar reprogramação 
#define DADOS_LCD  PORTD // 4 bits de dados  do LCD no PORTD
#define nibble_dados 1   // 0 para via de dados do LCD nos 4 LSBs  e 1 para MSBs
#define CONTR_LCD  PORTB // Pinos de controle estão no PORTB
#define RS         PB0   // Pino de instrução ou dado para o LCD
#define E          PB1   // Pino de Enable do LCD
#define back_light PB2	 // pino para informar se liga ou não o LCD


// sinal de habilitação do LCD
#define pulso_enable(); _delay_us(1); set_bit(CONTR_LCD,E); _delay_us(1); clr_bit(CONTR_LCD,E); _delay_us(45)

// Protótipo das Funções 
void cmd_LCD(unsigned char c,char cd);
void inic_LCD_4bits();
void escreve_LCD(char *c);
void escreve_LCD_Flash(const unsigned char *c);

#define LINHA PINC
#define COLUNA PORTD

unsigned char ler_teclado();

const unsigned char msg1[] PROGMEM = "Teclado 4x4\0";
const unsigned char msg2[] PROGMEM = "Tecla: \0";

const unsigned char teclado[4][4] PROGMEM = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

const unsigned char password PROGMEM = {"1", "2", "3"}

int main()
{
  	unsigned char nr;
  
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
 		nr = ler_teclado();
      	
      	if (nr != 0xFF) {
        	cmd_LCD(0xC8, 0);
          	cmd_LCD(nr, 1);
        }
    }			//laço infinito
}
	
	// envio de dados do display 4 vias 
	
	void cmd_LCD(unsigned char c,char cd)		//c éo dado e cd indica se é instrução ou caractere
	{
		if(cd==0) clr_bit(CONTR_LCD,RS);
		else      set_bit(CONTR_LCD,RS);
		
		// primeiro nibble de dados - MSB
		    #if (nibble_dados)									
				DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & c);   //compila código para os MSB do PORT
			#else
				DADOS_LCD = (DADOS_LCD & 0xF0) | (c>>4);   //compila código para os LSB do PORT
			#endif
				pulso_enable();

		// segundo nibble de dados - LSB
			#if (nibble_dados)
				DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & (c<<4));   //compila código para os MSB do PORT
			#else
				DADOS_LCD = (DADOS_LCD & 0xF0) | (0x0F & c );   //compila código para os LSB do PORT
			#endif
				pulso_enable();
				
			if((cd==0) && (c<4))  _delay_ms(2);   // se for instrução de retorno ou limpeza espera o LCD estar pronto

	}
	
	
	// Inicialização do LCD
	void inic_LCD_4bits()	//sequencia ditada pelo fabricnte do CI HD44780
	{
		clr_bit(CONTR_LCD,RS); // RS em 0 o dado do LCD será ua instrução
		clr_bit(CONTR_LCD,E);  // pino de habilitação em 0
		_delay_ms(20);
		
		//interface de 8 bits
		#if (nibble_dados)
			DADOS_LCD = (DADOS_LCD & 0x0F) | 0x30;
		#else
			DADOS_LCD = (DADOS_LCD & 0xF0) | 0x03;
		#endif
		
		// habilitação respeitando os tempos de resposta do LCD
		pulso_enable();
		_delay_ms(5);
		pulso_enable();
		_delay_us(200);
		pulso_enable();
		
		// Interface de 4 bits , deve ser enviado duas vezes 
		#if (nibble_dados)
			DADOS_LCD = (DADOS_LCD & 0x0F) | 0x20;
		#else
			DADOS_LCD = (DADOS_LCD & 0xF0) | 0x02;
		#endif
		
		pulso_enable();
		
		cmd_LCD(0x28,0);
		cmd_LCD(0x08,0); // desliga display
		cmd_LCD(0x01,0); // limpa todo o display
		cmd_LCD(0x0C,0); // mensagem aparente cursor inativo não piscando
		cmd_LCD(0x80,0); // inicializa cursor na primeir posição a esquerda ( 1ª linha )
	//	cmd_LCD(0x0D,0);    **************************************************
	}


//###########################################################################################

void escreve_LCD(char *c)
{
	for (; *c!=0;c++)  cmd_LCD(*c,1);
}
void escreve_LCD_Flash(const unsigned char *c)
{
	for (;pgm_read_byte(&(*c))!=0;c++)  cmd_LCD(pgm_read_byte(&(*c)),1);
	
}

unsigned char ler_teclado() {
	unsigned char n, j, tecla = 0xFF, linha;

	for(n = 0; n < 4; n++) {
		clr_bit(COLUNA, n);
		_delay_ms(10);

		linha = LINHA & 0b00011110;

		for(j = 1; j < 5; j++) {
          	if(!tst_bit(linha, j)){
				tecla = pgm_read_byte(&teclado[j-1][n]);
            }

		}
		set_bit(COLUNA, n);
	}
	return tecla;
}