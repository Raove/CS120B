/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab8_part2.c
 * Lab Section : 024
 * Lab 8 Part 2
 *
 * I acknowledge all content is my own work and also my partner's work, while following
 * the instructions and lab manuals as reference to my work
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}

//part2
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRD = 0xFF; PORTD = 0x00; //C is output
	unsigned char b_8 = 0x00;
	unsigned char d_2 = 0x00;
	unsigned short x= ADC;
	
	ADC_init();	
	
	while(1) {
		x=ADC;
		b_8=(char)x;
		d_2=(char)(x >> 8);
		PORTB=b_8;
		PORTD=d_2;		
	}
	return 0;
}
