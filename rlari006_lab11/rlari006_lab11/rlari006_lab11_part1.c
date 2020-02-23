/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab11_part1.c
 * Lab Section : 024
 * Lab 11 Part 1
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work and my partner
 */ 

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#endif

typedef struct _task {
	signed char state;
	unsigned long int period;
	unsigned long int elapsedTime;
	int (*TickFct)(int);
} task;

int KeyPadTask(int state){
	
	state=GetKeypadKey();
	
	switch(state){
		case '\0': PORTA = 0x1F; break;
		case '0': PORTA = 0x00; break;
		case '1': PORTA = 0x01; break;
		case '2': PORTA = 0x02; break;
		case '3': PORTA = 0x03; break;
		case '4': PORTA = 0x04; break;
		case '5': PORTA = 0x05; break;
		case '6': PORTA = 0x06; break;
		case '7': PORTA = 0x07; break;
		case '8': PORTA = 0x08; break;
		case '9': PORTA = 0x09; break;
		case 'A': PORTA = 0x0A; break;
		case 'B': PORTA = 0x0B; break;
		case 'C': PORTA = 0x0C; break;
		case 'D': PORTA = 0x0D; break;
		case '*': PORTA = 0x0E; break;
		case '#': PORTA = 0x0F; break;
		default: PORTA = 0x1B; break;
	}
	return state;
}

enum Display_states {Display_1,Display_2};

unsigned long int findGCD(unsigned long int a,unsigned long int b){
	unsigned long int c;
	while(1){
		c=a%b;
		if(c==0){return b;}
		a=b;
		b=c;
	}
	return 0;
}

int main()
{
	DDRA=0xFF; PORTA=0x00;
	DDRB=0xF0; PORTB=0x0F;
	DDRC=0xFF; PORTC=0x00;
	DDRD=0xFF; PORTD=0x00;
	
	static task task1;
	task *tasks[] = {&task1};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	task1.state = '\0';
	task1.period = 50;
	task1.elapsedTime = task1.period;
	task1.TickFct = &KeyPadTask;

	unsigned short i;
	unsigned long GCD = tasks[0]->period;
	for(i=1;i<numTasks;i++){
		GCD = findGCD(GCD,tasks[i]->period);
	}

	TimerSet(GCD);
	TimerOn();


	while (1)
	{
		for(i=0;i<numTasks;i++){
			if( tasks[i]->elapsedTime == tasks[i]->period){
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += GCD;
		}
		while(!TimerFlag){};
		TimerFlag=0;
	}
	return 0;
}