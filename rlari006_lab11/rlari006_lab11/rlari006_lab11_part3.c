/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab11_part3.c
 * Lab Section : 024
 * Lab 11 Part 3
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
	DDRC = 0xFF; PORTC = 0x00;
	DDRB = 0xF0; PORTB = 0x0F;
	DDRA = 0x00; PORTA = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	
	TimerSet(10);
	TimerOn();
	
	LCD_init();
	LCD_WriteData('0');
    /* Replace with your application code */
	unsigned char x;
    while (1) 
    {
		unsigned char y = 0x00;
		x = GetKeypadKey();
		switch(x){
			case '\0': y = 0x1F; break;
			case '1': y = 0x01; break;
			case '2': y = 0x02; break;
			case '3': y = 0x03; break;
			case '4': y = 0x04; break;
			case '5': y = 0x05; break;
			case '6': y = 0x06; break;
			case '7': y = 0x07; break;
			case '8': y = 0x08; break;
			case '9': y = 0x09; break;
			case '*': y = 0x0E; break;
			case '#': y = 0x0F; break;
			case 'A': y = 0x0A; break;
			case 'B': y = 0x0B; break;
			case 'C': y = 0x0C; break;
			case 'D': y = 0x0D; break;
			case '0': y = 0x00; break;
			//default: y = 0x1B; break;
		}
		while (!TimerFlag)
		{
		};
		TimerFlag = 0;
		if (y == 0x01 ||y == 0x02 ||y == 0x03 ||y == 0x04 ||y == 0x05 ||y == 0x06 ||y == 0x07 ||y == 0x08 ||y == 0x09 || y == 0x00)
		{
			LCD_Cursor(1);
			LCD_WriteData('0' + y);
	}
	else if (y == 0x0A)
	{
		LCD_Cursor(1);
		LCD_WriteData('A');
}
else if (y == 0x0B)
{
	LCD_Cursor(1);
	LCD_WriteData('B');
}
else if (y == 0x0C)
{
	LCD_Cursor(1);
	LCD_WriteData('C');
}
else if (y == 0x0D)
{
	LCD_Cursor(1);
	LCD_WriteData('D');
}
else if (y == 0x0E)
{
	LCD_Cursor(1);
	LCD_WriteData('*');
}
else if (y == 0x0F)
{
	LCD_Cursor(1);
	LCD_WriteData('#');
}
else if (y == 0x1F)
{
	LCD_Cursor(1);
	
}
else
{
	LCD_Cursor(1);
}
    }
}

