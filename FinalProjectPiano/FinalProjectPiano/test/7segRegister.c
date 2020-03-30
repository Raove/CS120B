/*
#include <avr/io.h>
#include "../headers/timer.h"

void transmit_data(unsigned char data)
{
	for(unsigned char i = 0; i < 8; i++)
	{
		PORTB = 0x08;
		PORTB |= ((data>>i) & 0x01);
		PORTB |= 0x02;
	}
	PORTB |= 0x04;
	PORTB = 0x00;
}

unsigned char countdown[] = { 0b10011001, 0b00001101, 0b00100101, 0b10011111};
unsigned char count = 0;
int main(void)
{
	DDRB = 0x0F; PORTB = 0xF0;
	TimerOn();
	TimerSet(250);
	TimerFlag = 0;
    while (1) 
    {
		transmit_data(countdown[count]);
		while(!TimerFlag);
		TimerFlag = 0;			
		count = count > 2 ? 0 : count + 1;
    }
}
/**/