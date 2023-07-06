/*
 * stepper_A4988N.cpp
 *
 * Created: 7/6/2023 7:15:20 PM
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define stepPin 0x02
#define dirPin 0x01

int main(void)
{
    DDRB = 0x03;
	PORTB = dirPin;
    while (1) 
    {
		for(int x = 0; x < 200; x++)
		{
			PORTB = (stepPin ^ dirPin);
			_delay_ms(500);
			PORTB = dirPin;
			_delay_ms(500);
		}
		_delay_ms(1000);
		PORTB = 0x00;
		for(int x = 0; x < 400; x++)
		{
			PORTB = stepPin;
			_delay_ms(500);
			PORTB = 0x00;
			_delay_ms(500);
		}
		_delay_ms(1000);
    }
}

