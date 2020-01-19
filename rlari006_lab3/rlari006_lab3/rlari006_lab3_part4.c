  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab3_part4.c
 * Lab Section : 024
 * Lab 3 Part 4
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
	unsigned char PB = 0x00;
	unsigned char PC = 0x00;
	
	while(1)
	{
		PB = (PINA & 0xF0) >> 4;
		PC = (PINA = 0x0F) << 4;
		
		PORTB = PB;
		PORTC = PC;
	}
}
