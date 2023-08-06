/*
 * Timer0.cpp
 *
 * Created: 7/31/2023 2:42:12 PM
 * Author : B550-E
 * Note Timer 0, 8-bit timer as time delay
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

void timer()
{
	TCCR0B = 0x05;	// 16MHZ/1024 = 15,625Hz or 1/15,625Hz = 64us, 10ms delay = 10ms/64us => 156 cycles 
	//TCNT0 = 100;		// (8 bit timer) 256 - 156 = 100 or  0x64
	TCNT0 = 72;	// (256-72)*64us = 11.76ms delay
	while((TIFR0 & 0x01) == 0);	// Timer overflow flag TCNT0 must overflow
	TIFR0 = 0x01;	// write 1 to clear the flag
}

int main(void)
{
	DDRD = 0xFF; PORTD = 0x00;
    while (1) 
    {
		PORTD ^= 0x01;
		for(int i = 1; i <= 85; i++)
		{
			timer();	// 11.76ms*85 = aprrox 1 second
		}
    }
}

