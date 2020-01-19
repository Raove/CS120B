  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab4_part2.c
 * Lab Section : 024
 * Lab 4 Part 2
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

enum state_button {start, increase, decrease, wait} button_state;
	
void LED_on();

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char C_swap = 0x07;
	button_state = start;
	
	PORTC = C_swap;
		
	while(1)
	{
		LED_on();
	}
}

void LED_on()
{
	char button1 = ~PINA & 0x01;
	char button2 = ~PINA & 0x02;
	unsigned char C_swap = 0x07;
	
	switch (button_state)
	{
		case start:
			if (!button1 && !button2)
			{
				button_state = wait;
			}
			else if (button1 && !button2)
			{
				button_state = increase;
			}
			else if (!button1 && button2)
			{
				button_state = decrease;
			}
			else
			{
				button_state = start;
			}
			break;
		case increase:
			if (!button1 && !button2)
			{
				button_state = start;
			}
			else if (button1 && button2)
			{
				button_state = 0x00;
			}
			else
			{
				button_state = start;
			}
			break;
		case decrease:
			if (!button1 && !button2)
			{
				button_state = start;
			}
			else if (button1 && button2)
			{
				button_state = 0x00;
			}
			else
			{
				button_state = start;
			}
			break;
		case wait:
			if (button1 && button2)
			{
				button_state = 0x00;
			}
			else if (button1 && !button2)
			{
				button_state = increase;
			}
			else if (!button1 && button2)
			{
				button_state = decrease;
			}
			else
			{
				button_state = start;
			}
			break;
	}
	switch (button_state)
	{
		case start:
			C_swap = start;
			break;
		case increase:
			if (C_swap < 9)
			{
				PORTC += 0x01;
			}
			break;
		case decrease:
			if (C_swap >= 1)
			{
				PORTC -= 0x01;
			}
		case wait:
			PORTC = 0x00;
			break;
		default:
			PORTC = 0x00;
			break;
	}
}