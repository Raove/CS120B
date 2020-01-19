  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab3_part5.c
 * Lab Section : 024
 * Lab 3 Part 5
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{	
	DDRB = 0xFE; PORTB = 0x00;
	DDRD = 0x00; PORTD = 0xFF;
	
	unsigned char PB = 0x00;
	unsigned char PD = 0x00;
	unsigned char airbag = 0x00;
	
	while(1)
	{
		PB = PINB & 0x01;
		PD = PIND;
		
		if ((PB ==1 && PD >= 69) || (PD >= 70))
		{
			airbag = 0x02;
		}
		else if ((PB ==0 && PD < 70 && PD > 5) || (PB == 1 && PD >= 2))
		{
			airbag = 0x04;
		}
		else
			airbag = 0x00;
		
		PORTB = PB | airbag;
	}
}
