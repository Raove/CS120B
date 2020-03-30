/*
#include <avr/io.h>
#include "usart_ATmega1284.h"


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFA; PORTD = 0x05;
	
	initUSART(0);
	USART_Flush(0);
	unsigned  char tmp;
	while (1)
	{
		while (!USART_HasReceived(0));		
		tmp = (unsigned char)USART_Receive(0);
		PORTB = tmp;		
	}
}
/**/