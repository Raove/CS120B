//*
#include <avr/io.h>
#include "../headers/pwm.h"
#include "../headers/timer.h"
#include "../headers/usart_ATmega1284.h"

#define REST 00
#define C2   65
#define C2_S 69
#define D2   73
#define D2_S 78
#define E2   82
#define F2   87
#define F2_S 92
#define G2   98
#define G2_S 104
#define A2   110
#define A2_S 116
#define B2   123
#define C3   131
#define C3_S 138
#define D3   147
#define D3_S 155
#define E3   165
#define F3   175
#define F3_S 185
#define G3   196
#define G3_S 208
#define A3   220
#define A3_S 233
#define B3   247
#define C4   262
#define C4_S 277
#define D4   294
#define D4_S 311
#define E4   330
#define F4   349
#define F4_S 370
#define G4   392
#define G4_S 415
#define A4   440
#define A4_S 466
#define B4   494
#define C5   523
#define C5_S 554
#define D5   587
#define D5_S 622
#define E5   659
#define F5   698
#define F5_S 740
#define G5   784
#define G5_S 831
#define A5   880
#define A5_S 932
#define B5   988
#define C6   1046
#define C6_S 1109
#define D6   1175
#define D6_S 1244
#define E6   1318
#define F6   1397
#define F6_S 1480
#define G6   1568
#define G6_S 1661
#define A6   1760
#define A6_S 1865
#define B6   1975
#define C7   2093
#define C7_S 2217
#define D7   2349
#define D7_S 2489
#define E7   2637
#define F7   2794
#define F7_S 2960
#define G7   3136
#define G7_S 3322
#define A7   3520
#define A7_S 3729
#define B7   3951
#define C8   4186

unsigned short AerodynamicSolo[] =
{
	REST, REST, REST,
	
	//SONG SOLO
	D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S,
	D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S,
	D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	
	
	D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S,
	D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S,
	D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	
	
	D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S, D6, F5_S, B6, F5_S,
	D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S, D6, G5_S, B6, G5_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S, D6, F6_S, B6, F6_S,
	D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S, D6, G6_S, B6, G6_S,
	G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6, G6, B6, E6, B6,
	E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5, E6, A5, C6_S, A5,
	
};

unsigned short AerodynamicSolo_Delay[] =
{
	625, 625, 625,
	
	//SONG SOLO
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	
	
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	
	
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,	
	
};

unsigned short SuperMarioBros[] =
{
	REST, REST, REST,
	
	//SONG INTRO

	E6, E6, REST, E6, REST, C6, E6, REST, G6, REST, REST, REST, G4, REST, REST, REST,
	C6, REST, REST, G5, REST, REST, E5, REST, REST, A5, REST, B5, REST, A5_S, A5, REST,
	G5, E6, E6, G6, A6, REST, F6, G6, REST, E6, REST, C6, D6, B5, REST, REST,
	C6, REST, REST, G5, REST, REST, G5, REST, REST, A5, REST, B5, REST, A5_S, A5, REST,
	G5, E6, E6, G6, A6, REST, F6, G6, REST, E6, REST, C6, D6, B5, REST, REST,
	
	//SONG VERSE
	
	REST, REST, G6, G6_S, F6, D6_S, REST, E6, REST, G5_S, A5, C6, REST, A5, C6, D6,
	REST, REST, G6, G6_S, F6, D6_S, REST, E6, REST, C7, REST, C7, C7, REST, REST, REST,
	REST, REST, G6, G6_S, F6, D6_S, REST, E6, REST, G5_S, A5, C6, REST, A5, C6, D6,
	REST, REST, D6_S, REST, REST, D6, REST, REST, C6, REST, REST, G3, G3, REST, C3, REST,
	
	//SONG BRIDGE
	C6, C6, REST, C6, REST, C6, D6, REST, E6, C6, REST, A5, G5, REST, REST, REST,
	C6, C6, REST, C6, REST, C6, D6, E6, G4, REST, REST, C4, REST, REST, G3, REST,
	C6, C6, REST, C6, REST, C6, D6, REST, E6, C6, REST, A5, G5, REST, REST, REST,
	E6, E6, REST, E6, REST, C6, E6, REST, G6, REST, REST, REST, G5, REST, REST, REST,
	
	//SONG OUTRO
	E6, C6, REST, G5, REST, REST, G5_S, REST, A5, F6, REST, F6, A5, REST, REST, REST,
	B5, A6, A6, A6, A6, G6, G6, F6, E6, C6, REST, A5, G5, REST, REST, REST,
	E6, C6, REST, G5, REST, REST, G5_S, REST, A5, F5, REST, A5, A5, REST, REST, REST,
	B5, F6, REST, F6, F6, E6, E6, D6, C6, E5, REST, E5, C5, REST, REST, REST,
	
};

unsigned short SuperMarioBros_Delay[] =
{
	625, 625, 625,
	
	//SONG INTRO
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	
	//SONG VERSE
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	
	//SONG BRIDGE
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	
	//SONG OUTRO
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
	
};

unsigned char Play;

enum States {wait, play_short, play_long, end_wait} state;

unsigned short count = 0x00;
long double Max_AerodynamicSolo = (sizeof(AerodynamicSolo) / sizeof(AerodynamicSolo[0]));
long double Max_SuperMario = (sizeof(SuperMarioBros) / sizeof(SuperMarioBros[0]));

void transmit_data(unsigned short data)
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

unsigned char countdown[] = 
{ 
	0b00001101, 0b00100101, 0b10011111, 0b00000011,
	
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,

	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,

	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 
	0b00000011,
};

void state_transitions()
{
	switch(state)
	{
		case wait:
			if(Play == 1){
				state = play_short;
			}
			else if(Play == 15){
				state = play_long;
			}
			else state = wait;
		break;
		
		case play_short:
		state = count < Max_AerodynamicSolo ? play_short : end_wait;
		break;
		
		case play_long:
		state = count < Max_SuperMario ? play_long : end_wait;
		break;
		
		case end_wait:
			if (Play == 1 || Play == 15){
				state = end_wait;
			}
			else state = wait;
			Play = 0x00;
		break;
		
		default:
		state = wait; break;
	}
}

void button_LED(unsigned char data){
	if (data == 2)
	{
		PORTA = 0xF0;
		PORTC = ~0x01;
	}
	else if (data == 3)
	{
		PORTA = 0xF0;
		PORTC = ~0x03;
	}
	else if (data == 4)
	{
		PORTA = 0xF0;
		PORTC = ~0x02;
	}
	else if (data == 5)
	{
		PORTA = 0xF0;
		PORTC = ~0x06;
	}
	else if (data == 6)
	{
		PORTA = 0xF0;
		PORTC = ~0x04;
	}
	else if (data == 7)
	{
		PORTA = 0xF0;
		PORTC = ~0x08;
	}
	else if (data == 8)
	{
		PORTA = 0xF0;
		PORTC = ~0x18;
	}
	else if (data == 9)
	{
		PORTA = 0xF0;
		PORTC = ~0x10;
	}
	else if (data == 10)
	{
		PORTA = 0xF0;
		PORTC = ~0x30;
	}
	else if (data == 11)
	{
		PORTA = 0xF0;
		PORTC = ~0x20;
	}
	else if (data == 12)
	{
		PORTA = 0xF0;
		PORTC = ~0x60;
	}
	else if (data == 13)
	{
		PORTA = 0xF0;
		PORTC = ~0x40;
	}
	else if (data == 14)
	{
		PORTA = 0xF0;
		PORTC = ~0x80;
	}
	else
	{
		PORTA = 0xF0;
		PORTC = ~0x00;
	}
}

void song_LED(unsigned short data){
	if (data == C2 || data == C3 || data == C4 || 
	data == C5 || data == C6 || data == C7 || data == C8)
	{
		PORTC = ~0x01;
	}
	else if (data == C2_S || data == C3_S || data == C4_S ||
	data == C5_S || data == C6_S || data == C7_S)
	{
		PORTC = ~0x03;
	}
	else if (data == D2 || data == D3 || data == D4 ||
	data == D5 || data == D6 || data == D7)
	{
		PORTC = ~0x02;
	}
	else if (data == D2_S || data == D3_S || data == D4_S ||
	data == D5_S || data == D6_S || data == D7_S)
	{
		PORTC = ~0x06;
	}
	else if (data == E2 || data == E3 || data == E4 ||
	data == E5 || data == E6 || data == E7)
	{
		PORTC = ~0x04;
	}
	else if (data == F2 || data == F3 || data == F4 ||
	data == F5 || data == F6 || data == F7)
	{
		PORTC = ~0x08;
	}
	else if (data == F2_S || data == F3_S || data == F4_S ||
	data == F5_S || data == F6_S || data == F7_S)
	{
		PORTC = ~0x18;
	}
	else if (data == G2 || data == G3 || data == G4 ||
	data == G5 || data == G6 || data == G7)
	{
		PORTC = ~0x10;
	}
	else if (data == G2_S || data == G3_S || data == G4_S ||
	data == G5_S || data == G6_S || data == G7_S)
	{
		PORTC = ~0x30;
	}
	else if (data == A2 || data == A3 || data == A4 ||
	data == A5 || data == A6 || data == A7)
	{
		PORTC = ~0x20;
	}
	else if (data == A2_S || data == A3_S || data == A4_S ||
	data == A5_S || data == A6_S || data == A7_S)
	{
		PORTC = ~0x60;
	}
	else if (data == B2 || data == B3 || data == B4 ||
	data == B5 || data == B6 || data == B7)
	{
		PORTC = ~0x40;
	}
	else
	{
		PORTC = ~0x00;
	}
}

void state_actions()
{
	switch(state)
	{
		case wait:
			count = 0x00;
			transmit_data(0b10011001);
			PORTC = 0xFF;
			TimerFlag = 1;
			set_PWM(0);
			break;
			
			case play_short:
			PORTA = 0x0F;
			transmit_data(countdown[count]);
			TimerSet(AerodynamicSolo_Delay[count]);
			TimerFlag = 0;
			song_LED(AerodynamicSolo[count]);
			set_PWM(AerodynamicSolo[count]);
			count += 1;
			break;
			
			case play_long:
			PORTA = 0x0F;
			transmit_data(countdown[count]);
			TimerSet(SuperMarioBros_Delay[count]);
			TimerFlag = 0;
			song_LED(SuperMarioBros[count]);
			set_PWM(SuperMarioBros[count]);
			count += 1;
			break;
		
		case end_wait:
			Play = 0x00;
			break;
		
		default:
			set_PWM(0);
			break;
	}
}

int main(void)
{
	DDRA = 0xFF; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFA; PORTD = 0x05;
	
	initUSART(0);
	PWM_on();
	TimerOn();
	TimerSet(0);
    while (1) 
    {
		if (USART_HasReceived(0))
		{
			Play = USART_Receive(0);			
		}
		else {
			Play = 0;
		}
		state_transitions();
		state_actions();
		button_LED(Play);
		while(!TimerFlag);
		USART_Flush(0);
    }
}
/**/
