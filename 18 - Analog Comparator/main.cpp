/*
 * analog_comparator.cpp
 *
 * Created: 7/31/2023 12:06:28 AM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

int main(void)
{
	DDRD = 0x10;
	DIDR1 = 0x03;
	ADCSRB &(1<<ACME);
	ACSR = 0x10;
    while (1) 
    {
		if(ACSR & (1<<5))
			PORTD |= (1<<4);
		else
			PORTD &= ~(1<<4);
    }
}

