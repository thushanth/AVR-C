/*
 * LED Strobe.cpp
 *
 * Created: 6/27/2023 10:48:42 AM
 * Modified: 6/30/2023 5:38:45 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i;
	DDRD = 0xff;	// Set PORT D as output Digital Pin 0 - 7
	PORTD = 0x00;	// Set all output on PORT D as logic low
	PORTD = 0x01;	// Set PD0 as logic high
	_delay_ms(100);
	while (1) 
	{
		for(i = 1; i <=7; i++)	// Go up telling which one to change logic state
		{
			PORTD <<= 1;
			_delay_ms(100);
		}
		for(i = 1; i <=7; i++) // Go down telling which one to change logic state
		{
			PORTD >>= 1;
			_delay_ms(100);
		}
	}
}
