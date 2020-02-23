/* Raoul Larios   rlari006@ucr.edu
 * rlari006_lab11_part2.c
 * Lab Section : 024
 * Lab 11 Part 2
 *
 * I acknowledge all content is my own work while following
 * the instructions and lab manuals as reference to my work and my partner's
 */ 

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#endif

unsigned int counter=0;
 unsigned char word[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','C','S','1','2','0','B',' ','i','s',' ','L','e','g','e','n','d','.','.','.',' ','w','a','i','t',' ','f','o','r',' ','i','t',' ','D','A','R','Y','!'};
unsigned int i=0; 

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

enum Display_states {Display_1,Display_2,Display_3};
	
int Display_Task(int state){
switch(state){
	case Display_1:
	LCD_WriteCommand(0x80);
	LCD_WriteCommand(0x01);
	
	
	for(i=0;i<18;i++){
	LCD_WriteData(word[counter+i]);
	}
	state=Display_2;
	break;	
	case Display_2:
	if(counter<37){
	counter=counter+1;
	state=Display_1;
	}
	else{
	counter=0;
	state=Display_3;
	}
	break;
	case Display_3:
	if(counter<5){
	counter=counter+1;
	state=Display_3;
	}
	else{
	counter=0;
	state=Display_1;}
	break;	
	default:
	
	break;	
		}
switch(state){
	case Display_1:
	break;
	case Display_2:
	break;
	case Display_3:
	break;
}
return state;
}

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
	
	static task task1, task2;
	task *tasks[] = {&task1, &task2};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	task1.state = '\0';
	task1.period = 50;
	task1.elapsedTime = task1.period;
	task1.TickFct = &KeyPadTask;
	

	task2.state = Display_1;
	task2.period = 200;
	task2.elapsedTime = task2.period;
	task2.TickFct = &Display_Task;


	unsigned short i;
	unsigned long GCD = tasks[0]->period;
	for(i=1;i<numTasks;i++){
		GCD = findGCD(GCD,tasks[i]->period);
	}
	
	TimerSet(GCD);
	TimerOn();
	LCD_init();
	LCD_ClearScreen();

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