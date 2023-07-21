/*
 * LED.cpp
 *
 * Created: 6/25/2023 6:59:46 PM
 * Modified: 6/30/2023 5:35:23 PM
 * Author : B550-E
 * Designed for understanding clocking frequency and Register Direction.
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0x20;	// Digital PIN 13 or on-built LED on Arduino Uno
	PORTB &= 0x00;
	while (1) 
	{
		PORTB ^=0xFF;	// Toggle LED State ON or OFF.
		_delay_ms(1000);
	}
}

