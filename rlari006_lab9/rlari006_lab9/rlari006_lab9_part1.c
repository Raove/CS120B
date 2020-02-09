/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab9_part1.c
 * Lab Section : 024
 * Lab 9 Part 2
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work
 */ 

#include <avr/io.h>

void set_PWM(double frequency){
	static double current_frequency;
	if (frequency != current_frequency)
	{
		if (!frequency)
		{
			TCCR3B &= 0x08;
		}
		else
		{
			TCCR3B |= 0x03;
		}
		if (frequency < 0.954)
		{
			OCR3A = 0xFFFF;
		}
		else if (frequency > 31250)
		{
			OCR3A = 0x0000;
		}
		else
		{
			OCR3A = (short)(8000000/(128*frequency)) -1;
		}
		TCNT3 = 0;
		current_frequency = frequency;
	}
}

void PWM_on(){
	TCCR3A = (1 << COM3A0);
	TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
	set_PWM(0);
}

void PWM_off(){
	TCCR3A = 0x00;
	TCCR3B = 0x00;
}

enum State {start, wait, C4_sound, D4_sound, E4_sound} state_button;
unsigned button = 0x00;
static double C4 = 261.63;
static double D4 = 293.66;
static double E4 = 329.63;
static double F4 = 349.23;
static double G4 = 392.00;
static double A4 = 440.00;
static double B4 = 493.88;
static double C5 = 523.25;

void Tick(){
	switch(state_button){
		case start:
			state_button = wait;
			break;
		case wait:
			if (button == 0x01)
			{
				state_button = C4_sound;
			}
			else if (button == 0x02)
			{
				state_button = D4_sound;
			}
			else if (button == 0x04)
			{
				state_button = E4_sound;
			}
			else
			{
				state_button = wait;
			}
			break;
		case C4_sound:
			if (button == 0x01)
			{
				state_button = C4_sound;
			}
			else
			{
				state_button = wait;
			}
			break;
		case D4_sound:
			if (button == 0x02)
			{
				state_button = D4_sound;
			}
			else
			{
				state_button = wait;
			}
			break;
		case E4_sound:
			if (button == 0x04)
			{
				state_button = E4_sound;
			}
			else
			{
				state_button = wait;
			}
			break;
		default:
			break;
	}
	switch(state_button){
		case wait:
			set_PWM(0);
			break;
		case C4_sound:
			set_PWM(C4);
			break;
		case D4_sound:
			set_PWM(D4);
			break;
		case E4_sound:
			set_PWM(E4);
			break;
		default:
			break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	PWM_on();
	state_button = start;
    /* Replace with your application code */
    while (1) 
    {
		button = ~PINA & 0x07;
		Tick();
    }
}

