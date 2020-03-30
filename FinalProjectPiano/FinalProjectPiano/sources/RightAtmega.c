/*
#include <avr/io.h>
#include "../headers/usart_ATmega1284.h"
#include "avr/eeprom.h"
#include "../headers/pwm.h"

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

#define C  (~PINA & 0x01)
#define CS (~PINA & 0x02)
#define D  (~PINA & 0x04)
#define DS (~PINA & 0x08)
#define E  (~PINA & 0x10)
#define F  (~PINC & 0x01)
#define FS (~PINC & 0x80)
#define G  (~PINC & 0x02)
#define GS (~PINC & 0x40)
#define A  (~PINC & 0x04)
#define AS (~PINC & 0x20)
#define B  (~PINC & 0x10)
#define CO (~PINC & 0x08)

#define INCREASE (~PINA & 0x80)
#define SONG1 (~PINA & 0x20)
#define SONG2 (~PINA & 0x40)

unsigned short keys[6][13] =
{
	{ C2, C2_S, D2, D2_S, E2, F2, F2_S, G2, G2_S, A2, A2_S, B2, C3 },
	{ C3, C3_S, D3, D3_S, E3, F3, F3_S, G3, G3_S, A3, A3_S, B3, C4 },
	{ C4, C4_S, D4, D4_S, E4, F4, F4_S, G4, G4_S, A4, A4_S, B4, C5 },
	{ C5, C5_S, D5, D5_S, E5, F5, F5_S, G5, G5_S, A5, A5_S, B5, C6 },
	{ C6, C6_S, D6, D6_S, E6, F6, F6_S, G6, G6_S, A6, A6_S, B6, C7 },
	{ C7, C7_S, D7, D7_S, E7, F7, F7_S, G7, G7_S, A7, A7_S, B7, C8 },
};

unsigned char transpose;

enum Transpose {wait, up, release} state;
void Transpose_SM()
{
	switch(state)
	{
		case wait:
		state = INCREASE ? up : wait;
		break;
		
		case up:
		state = release;
		break;
		
		case release:
		state = INCREASE ? release : wait;
		break;
		
		default:
		state = wait;
	}
	
	switch(state)
	{
		case up:
		transpose = transpose < 5 ? transpose + 1 : 1;
		eeprom_update_byte(0x00, transpose);
		break;
		
		default: 
		eeprom_update_byte(0x00, transpose);
		break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFA; PORTD = 0x05;
	
	initUSART(0);
	PWM_on();
	
	transpose = (eeprom_read_byte(0x00) == 0xFF) ? 2 : eeprom_read_byte(0x00);
	while (1) 
    {
		Transpose_SM();			
			
		if(SONG1){USART_Send(1, 0);}
		else if(C ){set_PWM(keys[transpose][0]);
			USART_Send(2, 0);}
		else if(CS){set_PWM(keys[transpose][1]);
			USART_Send(3, 0);}
		else if(D ){set_PWM(keys[transpose][2]);
			USART_Send(4, 0);}
		else if(DS){set_PWM(keys[transpose][3]);
			USART_Send(5, 0);}
		else if(E ){set_PWM(keys[transpose][4]);
			USART_Send(6, 0);}
		else if(F ){set_PWM(keys[transpose][5]);
			USART_Send(7, 0);}
		else if(FS){set_PWM(keys[transpose][6]);
			USART_Send(8, 0);}
		else if(G ){set_PWM(keys[transpose][7]);
			USART_Send(9, 0);}
		else if(GS){set_PWM(keys[transpose][8]);
			USART_Send(10, 0);}
		else if(A ){set_PWM(keys[transpose][9]);
			USART_Send(11, 0);}
		else if(AS){set_PWM(keys[transpose][10]);
			USART_Send(12, 0);}
		else if(B ){set_PWM(keys[transpose][11]);
			USART_Send(13, 0);}
		else if(CO){set_PWM(keys[transpose][12]);
			USART_Send(14, 0);}
		else if(SONG2){USART_Send(15, 0);}
		else       {set_PWM(0);
			USART_Send(0, 0);}
			
		transpose = (transpose >= 0 && transpose <= 4) ? transpose : 2;
    }
	
}
/**/