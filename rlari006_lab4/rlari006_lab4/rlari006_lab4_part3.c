  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab4_part3.c
 * Lab Section : 024
 * Lab 4 Part 3
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

enum state_lock {start, hashtag, Y, locked, unlocked} lock_state;
	
char unlock(unsigned char lock);

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char lock = 0x00;
			
	while(1)
	{
		unlock(lock);
	}
}

char unlock(unsigned char lock) {
	lock = PINA & 0x87;
	
	switch (lock_state)
	{
		case start:
			lock_state = locked;
			break;
		case hashtag:
			if (lock == 0x02)
			{
				lock_state = Y;
			}
			else
			{
				locked;
			}
			break;
		case Y:
			if (lock == 0x80)
			{
				lock_state = locked;
			}
			else if (lock == 0x01)
			{
				lock_state = unlocked;
			}
			else
			{
				Y;
			}
			break;
		case locked:
			if (lock == 0x04)
			{
				lock_state = hashtag;
			}
			else
			{
				locked;
			}
			break;
		default:
			break;
	}
	switch (lock_state)
	{
		case unlocked:
			PORTB = 0x01;
			break;
		default:
			PORTB = 0x00;
			break;
	}
}