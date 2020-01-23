  
/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab4_part5.c
 * Lab Section : 024
 * Lab 4 Part 5
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

enum state_lock {start, locked, unlocked, lockdoor, correct, incorrect} lock_state;
	
char unlock(unsigned char lock, unsigned char position);
unsigned char iscorrect(unsigned char position);

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char lock = 0x00;
	unsigned char position = 0;
			
	while(1)
	{
		unlock(lock, position);
		position++;
	}
}

unsigned char iscorrect(unsigned char position)
{
	unsigned char button_sequence[3] = {0x01, 0x02, 0x01};
	if (button_sequence[position - 1] == PINA)
	{
		return 0x01;
	}
	return 0x00;
}

char unlock(unsigned char lock, unsigned char position) {
	lock = PINA & 0x87;
	
	switch (lock_state)
	{
		case start:
			lock_state = locked;
			break;
		case unlocked:
			if (lock == 0x04)
			{
				lock_state = lockdoor;
			}
			else if (lock == 0x80)
			{
				locked;
			}
			else
			{
				locked;
			}
			break;
		case locked:
			if ((lock == 0x04 && position != 3) || (lock == 0x02 
			&& position != 3) || (lock == 0x01 && position != 3))
			{
				lock_state = locked;
			}
			else if (iscorrect(position) && position == 3)
			{
				lock_state = correct;
			}
			else
			{
				locked;
			}
			break;
		case lockdoor:
			if (lock == 0x80)
			{
				lock_state = locked;
			}
			else if (lock == 0x02)
			{
				lock_state = locked;
			}
			else
			{
				unlocked;
			}
			break;
		case incorrect:
			if (lock == 0x04)
			{
				lock_state = locked;
			}
			else
			{
				unlocked;
			}
			break;
		case correct:
			if (lock == 0x00)
			{
				lock_state = unlocked;
			}
			else
			{
				unlocked;
			}
			break;
		default:
			lock_state = locked;
			break;
	}
	switch (lock_state)
	{
		case unlocked:
			PORTB = 0x01;
			position = 0;
			break;
		default:
			PORTB = 0x00;
			break;
	}
}