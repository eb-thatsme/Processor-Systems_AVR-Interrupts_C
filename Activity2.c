# define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
//#include "SSD1306.h"
//#include "SSD1306.c" //Not sure why I need to include this file here
// Declare Global Variables
volatile int counter0;
//Define all inputs and outputs
#define PINB0 0
#define PINB1 1
#define DispDir DDRA
#define DispPort PORTA
int main(void)
{
	DDRB = (0<<PINB0);
	DDRB = (0<<PINB1);  //PINB0 and PINB1 is input
	PORTB=0XFF; // activate pull ups
	DispDir = 0xff; //Activate DDRA as output
	DispPort = 0xff; //Activate PORTA as output
	counter0 = 0;// Initialize counter
	DDRD = 0;// Port D all inputs
	PORTD |= (1<<2)|(1<<3);// Set Pull up resistor PD2 (INT0) and PD3 (INT1)
	EIMSK=(1<<INT0)|(1<<INT1); //unmask INT0 and INT1
	EICRA=0X00000001; //INT0 and INT1 WILL ACTIVATE any logical change TRIGGER
	sei();// Set Interrupt Flag
	char array[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //Array of numbers 0-9 in hex

	while(1)
	{
		// Wait For Interrupts and Update PORTA
		if(counter0 > 9){
			PORTA = 0b10000000; //If PORTA >  10, PINA7 is high
			}else{
			PORTA = array[counter0];
		}
	}
}
// External Interrupt on Port D Pin 2
ISR(INT0_vect, ISR_BLOCK)
{
	unsigned char isHigh;
	isHigh= PINB & (1 << PINB0);
	if (~isHigh) counter0++; // If PINB0 is low, increment counter
	_delay_ms(2000);	//Delay to make sure value doesn't change too quickly
}
// External Interrupt on Port D Pin 3
ISR(INT1_vect, ISR_BLOCK)
{
	unsigned char isHigh1;
	isHigh1= PINB & (1 << PINB1);
	if (~isHigh1) counter0--; // If PINB1 is low, decrement counter
	_delay_ms(2000);	//Delay to make sure value doesn't change too quickly
}	
