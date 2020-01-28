  
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
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x66;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x77;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x88;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x99;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0xAA;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0xFF;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0xAA;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x99;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x88;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x77;
		for (long i = 0; i < 7000; i++)
		{
		}
		PORTC = 0x66;
	}
}
