/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab6_part2.c
 * Lab Section : 024
 * Lab 6 Part 2
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0;

unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

void TimerOn(){
	TCCR1B = 0x0B;
	OCR1A = 125;
	TIMSK1 = 0x02;
	TCNT1 = 0;
	_avr_timer_cntcurr = _avr_timer_M;
	SREG |= 0x80;
}

void TimerOff(){
	TCCR1B = 0x00;
}

void TimeISR(){
	TimerFlag = 1;
}

ISR(TIMER1_COMPA_vect){
	_avr_timer_cntcurr--;
	if (_avr_timer_cntcurr == 0)
	{
		TimeISR();
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

void TimerSet(unsigned long M){
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

enum States {start, one, two, three, hold} state;

int main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	TimerSet(100);
	TimerOn();
	unsigned char tmpB = 0x01;
	unsigned char button = 0x00;
    /* Replace with your application code */
    while (1) 
    {
			switch(state){
				case start:
					state = one;
					break;
				case one:
					state = two;
					break;
				case two:
					state = three;
					break;
				case three:
					state = one;
					break;
				case hold:
					
					break;
				default:
				state = start;
				break;
			}
			switch(state){
				case one:
					tmpB = 0x01;
					PORTB = tmpB;
					TimerSet(30);
					while((!TimerFlag && button) || !button){
						button = PINA & 0x01;
						if (!button)
						{
							state = hold;
						}
					};
					TimerFlag = 0;
					break;
				case two:
					tmpB = 0x02;
					PORTB = tmpB;
					TimerSet(30);
					while((!TimerFlag && button) || !button){
						button = PINA & 0x01;
						if (!button)
						{
							state = hold;
						}
					};
					TimerFlag = 0;
					break;
				case three:
					tmpB = 0x04;
					PORTB = tmpB;
					TimerSet(100);
					while((!TimerFlag && button) || !button){
						button = PINA & 0x01;
						if (!button)
						{
							state = hold;
						}
					};
					TimerFlag = 0;
					break;
				case hold:
					while((!TimerFlag && button) || !button){
						button = PINA & 0x01;
						if (!button)
						{
							state = start;
						}
					};
					TimerFlag = 0;
					break;
			}
    }
}

