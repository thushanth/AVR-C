/*
 * Timer1_Delay.cpp
 *
 * Created: 8/1/2023 5:58:47 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

void timer()
{
	while((TIFR1 & 0x01) == 0);
	TIFR1 = 0x01;	// Clar TOV Flag
}

int main(void)
{
    DDRD = 0x01;
	PORTD = 0x00;
	TCCR1A = 0x00;
	TCCR1B = 0x03;		// 16MHz/64 prescaler = 250kHz or 4us 
	TCNT1 = 0x0000;
    while (1) 
    {
		PORTD ^= 0x01; // delay = 4us * (65536-0) = 262ms, note the 65k comes from 16 bit timer.
		timer();
    }
}

