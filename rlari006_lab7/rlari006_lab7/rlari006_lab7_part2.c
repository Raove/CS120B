/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab7_part2.c
 * Lab Section : 024
 * Lab 7 Part 2
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "io.h"
#include "io.c"

volatile unsigned char TimerFlag = 0;
unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

enum States {start, one, two, three} state;

void LCD_Game();

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

unsigned char score = 0x05;
unsigned char count = 1;

void LCD_Game()
{	
	switch(state)
	{
		case start:
			state = one;
			break;
		case one:		
			PORTB = 0x01;
			state = two;
			count = 1;
			while(!TimerFlag){
				unsigned char button = ~PINA & 0x01;
				if (button && count == 1)
				{
					score--;
					count++;
				}
			};
			TimerFlag = 0;
			break;
		case two:
			PORTB = 0x02;
			state = three;
			count = 1;
			while(!TimerFlag){
				unsigned char button = ~PINA & 0x01;
				if (button && count == 1)
				{
					score++;
					count++;
				}
			};
			TimerFlag = 0;
			break;
		case three:
			PORTB = 0x04;
			state = one;
			count = 1;
			while(!TimerFlag){
				unsigned char button = ~PINA & 0x01;
				if (button && count == 1)
				{
					score--;
					count++;
				}
			};
			TimerFlag = 0;
			break;
		default:
			state = start;
			break;
	}	
	
	if (score >= 0x09)
	{
		PORTB = 0x07;
		LCD_DisplayString(1, "Victory!");
		while (!TimerFlag)
		{
		};
		TimerFlag = 0;
	}
	else if (score <= 0x00)
	{
		PORTB = 0x07;
		LCD_DisplayString(1, "You lose!");
		while (!TimerFlag)
		{
		};
		TimerFlag = 0;
	}
	else
	{
		LCD_Cursor(1);
		LCD_WriteData(score + '0');
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	TimerOn();
	TimerSet(120);
	
	LCD_init();
	
    while (1) 
    {
		LCD_Game();
	}
}

