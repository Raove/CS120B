/*
#include <avr/io.h>
#include "../headers/timer.h"

int main(void)
{
	DDRA = 0xFF; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	TimerOn();
	//TimerSet(100);
	unsigned char ROW[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
	unsigned char COL[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
	
	unsigned char num[3][8] = 
	{
		{ 0b11111111, 0b11111111, 0b11000000, 0b11111111, 0b11111111, 0b11000000, 0b11111111, 0b11111111 },
		{ 0b11111111, 0b11111111, 0b11000000, 0b11111111, 0b11111111, 0b00000011, 0b11111111, 0b11111111 },
		{ 0b00001111, 0b00001111, 0b00011000, 0b00011000, 0b00011000, 0b00011000, 0b11111111, 0b11111111 }		
	};
	
	TimerFlag = 0;
	while (1) 
    {
	    PORTA = 0xFF;
		for(unsigned char row = 0; row < sizeof(ROW); row++)
		{
			TimerSet(250);
			PORTC = ~COL[row];
			while(!TimerFlag);
			TimerFlag = 0;
		}
    }	
	return 0;
}
/**/