  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab3_part1.c
 * Lab Section : 024
 * Lab 3 Part 1
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char counter = 0x00;
	while(1)
	{
		if (GetBit(PINA, 0)) { 
			counter++;
		}
		if (GetBit(PINA, 1)) { 
			counter++;
		}
		if (GetBit(PINA, 2)) { 
			counter++;
		}
		if (GetBit(PINA, 3)) { 
			counter++;
		}
		if (GetBit(PINA, 4)) { 
			counter++;
		}
		if (GetBit(PINA, 5)) { 
			counter++;
		}
		if (GetBit(PINA, 6)) { 
			counter++;
		}
		if (GetBit(PINA, 7)) { 
			counter++;
		}
		if (GetBit(PINB, 0)){
			counter++;
		}
		if (GetBit(PINB, 0)){
			counter++;
		}
		if (GetBit(PINB, 1)) { 
			counter++;
		}
		if (GetBit(PINB, 2)) { 
			counter++;
		}
		if (GetBit(PINB, 3)) { 
			counter++;
		}
		if (GetBit(PINB, 4)) { 
			counter++;
		}
		if (GetBit(PINB, 5)) { 
			counter++;
		}
		if (GetBit(PINB, 6)) { 
			counter++;
		}
		if (GetBit(PINB, 7)) { 
			counter++;
		}
		if (GetBit(PINB, 0)){
			counter++;
		}
		PORTC = counter; // Displaying counter on PORTC
		counter = 0x00; //Reset the counter for debugging
	}
}
