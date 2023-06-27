/*
 * LED.cpp
 *
 * Created: 6/25/2023 6:59:46 PM
 * Author : B550-E
 * Designed for understanding clocking frequency and Register Direction.
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DDRB = 0x20;
	PORTB &= 0x00;
	while (1) 
    {
		PORTB ^=0xFF;
		_delay_ms(1000);
    }
}

