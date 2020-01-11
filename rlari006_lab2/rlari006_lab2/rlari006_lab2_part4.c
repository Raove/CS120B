/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab2_part4.c
 * Lab Section : 024
 * Lab 2 Part 4 CHALLENGE
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00;	PORTA = 0xFF;	// Configure port A's 8 pins as inputs
    DDRB = 0x00;	PORTB = 0xFF;	// Configure port B's 8 pins as inputs
	DDRC = 0x00;	PORTC = 0xFF;	// Configure port C's 8 pins as inputs
	DDRD = 0xFF;	PORTD = 0x00;	// Configure port D's 8 pins as outputs
    
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char weight = 0x00;

    while(1)
    {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		tmpD = 0x00; // Different because this is for the weight report
		weight = tmpA + tmpB + tmpC;

		if (tmpA+tmpB+tmpC >= 140)
		{
			tmpD = tmpD | 0x01; // Car exceeds 140 kg
		}
		if ((tmpA - tmpC) > 80)
		{
			tmpD = tmpD | 0x02;	// Car A and C difference exceeds 80 kg
		}
		if (tmpD == 0x01)
		{
			PORTD = tmpD; //Display that car exceeds 140 kg
		}
		if (tmpD == 0x02)
		{
			PORTD = tmpD; //Display that car A and C difference is greater than 80 kg
		}


		tmpD = weight + ((tmpD) >> 2); // Shift bit
		PORTD = tmpD;	// Show approximate weight
		weight = 0x00; // Reset weight for loop
    }
}