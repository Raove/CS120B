/*
 * rlari006_lab7.c
 *
 * Created: 1/30/2020 4:07:21 PM
 * Author : Name
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "io.h"
#include "io.c"

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
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char lcd_number = 0x00;
	
	TimerSet(10);
	TimerOn();
	
	LCD_init();
	LCD_WriteData('0');
    /* Replace with your application code */
    while (1) 
    {
		if ((~PINA & 0x01) && (~PINA & 0x02))
		{
			lcd_number = 0x00;
		}
		else if ((~PINA & 0x01) && (lcd_number < 9))
		{
			lcd_number += 0x01;
		}
		else if ((~PINA & 0x02) && (lcd_number >= 1))
		{
			lcd_number -= 0x01;
		}
		while (!TimerFlag)
		{
		};
		TimerFlag = 0;
		LCD_Cursor(1);
		LCD_WriteData('0' + lcd_number);
    }
}

