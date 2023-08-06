/*
 * Timer1_Counter.cpp
 *
 * Created: 8/1/2023 6:41:37 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

void timer()
{
	while((TIFR1 & 0x01) == 0);
	TIFR1 = 0x01;
}


int main(void)
{
	DDRD = 0x01;	// PD5 for T1(Timer1 External Counter Input)
	PORTD = 0x00;
	TCCR1A = 0x00;
	TCCR1B = 0x07;	//Rising Edge Clock
	TIMSK1 = 0x01;	// TOIE1 - Overflow interrupt enable
	TCNT1 = 0xFFFA;	// Press 5 more times to trigger led on PD0
	PORTD = 0x00;
	timer();
	PORTD = 0x01;
    while (1);
}

