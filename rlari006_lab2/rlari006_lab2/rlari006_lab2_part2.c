/*
 * rlari006_lab2_part2.c
 *
 * Created: 1/11/2020 10:40:35 AM
 * Author : Raoul Larios
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00;	PORTA = 0xFF;	// Configure port A's 8 pins as inputs
    DDRB = 0xFF;	PORTB = 0x00;	// Configure port B's 8 pins as outputs
    // Initialize output on PORTB to 0x00
	unsigned char cntavail;
	unsigned char park_space_1;
	unsigned char park_space_2;
	unsigned char park_space_3;
	unsigned char park_space_4;

    while(1)
    {
        
    }
}