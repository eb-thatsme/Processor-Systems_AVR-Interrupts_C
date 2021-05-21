/*
 * Lab10Act3.c
 *
 * Created: 4/16/2020 8:12:33 PM
 * Author : Ellisa
 */ 

#include "avr/io.h"
#include "avr/interrupt.h"

ISR (TIMER0_OVF_vect)	//ISR for Timer0 overflow
{
	TCNT0 = -41;		//value for 3kHz
	PORTD ^= PORTD;	//toggle PORTD
}

int main ()
{

	TCNT0 = -41;		//timer value for 3kHz
	TCCR0A = 0x00;
	TCCR0B = 0x03;		//Normal mode, int clk, 256 prescaler

	TIMSK0 = (1<<TOIE0);	//enable Timer0 overflow interrupt
	sei ();			//enable interrupts

	DDRB = 0x00;		//make PORTC input
	PORTB = 0xFF;		//enable pull-up resistors
	DDRD = 0xFF;		//make PORTD output
	DDRA = 0xff;			//make PORTA output

	while (1)			//wait here
	PORTA = PINB;		//Send pinB data to PORTA
}
