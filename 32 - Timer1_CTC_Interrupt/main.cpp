/*
 * Timer1_Interrupt.cpp
 *
 * Created: 8/1/2023 6:53:42 PM
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_OVF_vect)
{
	PORTD ^= 0x01;	
	TCNT1 = 0x9E58;
}

int main(void)
{
	DDRD = 0x01;
	TIMSK1 = 0x01;	// Timer Overflow Interrupt Enable
	PORTD = 0x00;	
	TCCR1A = 0x00;	
	TCCR1B = 0x03;	
	TCNT1 = 0x9E58;	// 4us * (65536-40536) = 99.99ms
	sei(); 
    while (1);
}

