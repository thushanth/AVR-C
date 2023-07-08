/*
 * stepper_A4988N.cpp
 *
 * Created: 7/6/2023 7:15:20 PM
 * Modified: 8/7/2023 4:29:51 PM
 * Author : B550-E
 * Note: Works but motor spins too slow. 
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0x18;	// DIR - PD4, STEP PD3 1 as output
	_delay_ms(100);
    while (1) 
    {
		PORTD = 0x10;
		_delay_ms(100);
		for(int x = 0; x < 20; x++)
		{
			PORTD = 0x18;
			_delay_ms(500);
			PORTD = 0x10;
			_delay_ms(500);
		}
		PORTD = 0x00;
		_delay_ms(100);
		for(int x = 0; x < 20; x++)
		{
			PORTD = 0x08;
			_delay_ms(500);
			PORTD = 0x00;
			_delay_ms(500);
		}
    }
}

