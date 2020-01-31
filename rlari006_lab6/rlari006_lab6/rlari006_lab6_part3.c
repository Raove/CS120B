/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab6_part3.c
 * Lab Section : 024
 * Lab 6 Part 3
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

enum state_button {start, increase, decrease, i_wait, d_wait, wait, reset} button_state;

int main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	TimerSet(100);
	TimerOn();
	
	unsigned char C_swap = 0x07;
	button_state = start;
	
    /* Replace with your application code */
    while (1) 
    {
	    unsigned char button1 = ~PINA & 0x01;
	    unsigned char button2 = ~PINA & 0x02;
		
		switch (button_state)
		{
			case start:
				if (button1)
				{
					button_state = i_wait;
				}
				else if (button2)
				{
					button_state = d_wait;
				}
				else
				{
					button_state = start;
				}
				break;
			case increase:
				button_state = start;
				break;
			case i_wait:
				if (button1 && button2)
				{
					button_state = reset;
				}
				else if (button1)
				{
					if (button1)
					{
						while (!TimerFlag && button1)
						{
							button_state = increase;
						};
					}
					else
					{
						button_state = i_wait;
						TimerOn();
					}
				}
				else
				{
					button_state = increase;
				}
				break;
			case decrease:
				button_state = start;
				break;
			case d_wait:
				if (button1 && button2)
				{
					button_state = reset;
				}
				else if (button2)
				{
					if (button2)
					{
						while (!TimerFlag && button2)
						{
							button_state = decrease;
						};
					}
					else
					{
						button_state = d_wait;
						TimerOn();
					}
				}
				else
				{
					button_state = decrease;
				}
				break;
			case reset:
				if (button1 || button2)
				{
					button_state = reset;
				}
				else
				{
					button_state = start;
				}
				break;
			default:
				button_state = start;
				break;
		}
		switch (button_state)
		{
			case increase:
				if (C_swap < 0x09)
				{
					C_swap += 0x01;
				}
				PORTB = C_swap;
				TimerFlag = 0;
				break;
			case decrease:
				if (C_swap >= 0x01)
				{
					C_swap -= 0x01;
				}
				PORTB = C_swap;
				TimerFlag = 0;
				break;
			case reset:
				C_swap = 0x00;
				PORTB = C_swap;
				break;
			default:
				PORTB = C_swap;
				break;
		}
	}
}

