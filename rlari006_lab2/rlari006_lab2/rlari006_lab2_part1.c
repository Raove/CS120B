/*
 * rlari006_lab2_part1.c
 *
 * Created: 1/11/2020 9:52:04 AM
 * Author : Raoul Larios
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00;	PORTA = 0xFF;	// Configure port A's 8 pins as inputs
	DDRB = 0xFF;	PORTB = 0x00;	// Configure port B's 8 pins as outputs
									// Initialize output on PORTB to 0x00
	unsigned char door = 0x00;
	unsigned char sensor = 0x00;

	while(1)
	{
		sensor = PINA & 0x02;	// PA1 input
		door = PINA & 0x01;		// PA0 input
		if ((sensor == 0x00) && (door == 0x01))
		{
			PORTB = 0x01;
		}
		else
			PORTB = 0x00;
	}
}

