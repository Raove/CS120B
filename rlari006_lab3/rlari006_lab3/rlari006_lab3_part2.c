  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab3_part2.c
 * Lab Section : 024
 * Lab 3 Part 2
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
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char fuel = 0x00;
	unsigned char meter = 0x00;
	while(1)
	{
		fuel = PINA & 0x0F;
		if(fuel > 12){
			meter = 0x3F;
		}
		else if (fuel > 9){
			meter = 0x3E;
		}
		else if (fuel > 6){
			meter = 0x3C;
		}
		else if (fuel > 2){
			meter = 0x30;
		}
		else if (fuel > 0){
			meter = 0x20;
		}
		else
			meter = 0x00;
			
		PORTC = meter; // Displaying fuel level on PORTC
		
		if (fuel < 5)
		{
			PORTC = meter | 0x40;
		}
		else
			PORTC = meter;
		
		meter = 0x00; //Reset the meter for debugging
	}
}
