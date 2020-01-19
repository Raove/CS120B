  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab4_part1.c
 * Lab Section : 024
 * Lab 4 Part 1
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

enum button {LED, LED1_PB0, LED2_PB1} button_state;
	
void LED_on(char button);

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char button;
	button_state = LED;
		
	while(1)
	{
		button = PINA & 0x01;
		LED_on(button);
	}
}

void LED_on(char button)
{
	switch (button_state)
	{
		case LED:
			button_state = LED1_PB0;
			break;
		case LED1_PB0:
			if (button)
			{
				button_state = LED2_PB1;
			}
			else if (!button)
			{
				button_state = LED1_PB0;
			}
			break;
		case LED2_PB1:
			if (button)
			{
				button_state = LED1_PB0;
			}
			else if (!button)
			{
				button_state = LED2_PB1;
			}
			break;
		default:
			button_state = LED;
			break;
	}
	switch (button_state)
	{
		case LED1_PB0:
			PORTB = 0x01;
			break;
		case LED2_PB1:
			PORTB = 0x02;
			break;
		default:
			PORTB = 0x01;
			break;
	}
}