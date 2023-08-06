/*
 * Timer0_Interrupt.cpp
 *
 * Created: 7/31/2023 11:01:51 PM
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)
{
	PORTD ^= 0x01;
	TCNT0 = 0x00;
}

int main(void)
{
    DDRD = 0xFF;
	PORTD = 0x00;
	TIMSK0 = 0x01;
	TCCR0B = 0x05;
	TCNT0 = 0x00;	//64us*256 = 16.384ms will cause the interrupt to be called and reset the counter. LED will blink super fast!
    sei();
	while (1){}
}

