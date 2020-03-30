/*
#include <avr/io.h>
#include "usart_ATmega1284.h"

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

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFA; PORTD = 0x05;
	
	TimerSet(10);
	TimerOn();
	initUSART(0);
	USART_Flush(0);
	unsigned char button1;
	unsigned char button2;
	while (1)
	{	
		if (USART_IsSendReady(0))
		{		
			button1 = (~PINA & 0x01);
			button2 = (~PINA & 0x02);
			USART_Send(button1+button2, 0);
			PORTB = (~PINA & 0x01) + (~PINA & 0x02);
			//USART_Send(0xFF, 0);
			while (USART_HasTransmitted(0))
			{
				
			}
		}
		while (!TimerFlag){};
		TimerFlag = 0;
	}
}
/**/