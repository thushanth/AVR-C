/*
 * Timer0_counter.cpp
 *
 * Created: 7/31/2023 10:52:10 PM
 * Author : B550-E
 *
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

void timer()
{
	while((TIFR0 & 0x01) == 0);
}

int main(void)
{
    DDRD = 0x01;	//PD4, Because PD4 is T0 as function of Timer/Counter External Counter Input 
	PORTD = 0x00;
	TCCR0B = 0x07; // Ext clock source on rising edge
	TCNT0 = 0xFA;	// loaded with value when pressed 6 times, it will overflow and set the LED as high to indicate the counter has overflowed. TCNT contains the the counter and has a max of 256 or 0xFF.
	TIMSK0 = 0x01;	// Timer0 Overflow is enabled
	PORTD = 0x00;
	timer();
	PORTD = 0x01;
	
	while(1);
}

