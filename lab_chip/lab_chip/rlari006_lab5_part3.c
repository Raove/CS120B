  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab5_part3.c
 * Lab Section : 024
 * Lab 5 Part 3
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
		
	while(1)
	{
		PORTC = 0x00;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x11;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x22;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x33;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x44;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x55;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x66;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x77;
		for (long i = 0; i < 10000; i++)
		{
		}
		PORTC = 0x88;
	}
}
