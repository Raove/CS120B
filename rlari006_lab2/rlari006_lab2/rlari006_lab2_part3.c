/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab2_part3.c
 * Lab Section : 024
 * Lab 2 Part 3
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00;	PORTA = 0xFF;	// Configure port A's 8 pins as inputs
    DDRB = 0xFF;	PORTB = 0x00;	// Configure port B's 8 pins as outputs
    // Initialize output on PORTB to 0x00
	unsigned char cntavail = 0x00;
	unsigned char park_space_1 = 0x00;
	unsigned char park_space_2 = 0x00;
	unsigned char park_space_3 = 0x00;
	unsigned char park_space_4 = 0x00;

    while(1)
    {
        park_space_1 = PINA & 0x01;
		park_space_2 = PINA & 0x02;
		park_space_3 = PINA & 0x04;
		park_space_4 = PINA & 0x08;
		
		if (park_space_1 == 0x01)
		{
    		cntavail = cntavail +0x01;
		}
		if (park_space_2 == 0x02)
		{
    		cntavail = cntavail +0x01;
		}
		if (park_space_3 == 0x04)
		{
    		cntavail = cntavail +0x01;
		}
		if (park_space_4 == 0x08)
		{
    		cntavail = cntavail +0x01;
		}
		if (cntavail == 4)
		{
			cntavail = 0x80; //lot full so PC7 is set to 1 to indicate full
		}
		PORTC = cntavail;
		cntavail = 0;	// Have to reset it because it loops and increases the number
    }
}