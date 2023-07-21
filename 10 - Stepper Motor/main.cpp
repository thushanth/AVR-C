/*
 * stepper_A4988N.cpp
 *
 * Created: 7/6/2023 7:15:20 PM
 * Modified: 18/7/2023 6:57:34 PM
 * Author : B550-E
 * Note: if you want more revs, #revs * 200 in the for loop. 
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
		for(int x = 0; x < 200; x++)
		{
			PORTD = 0x18;
			_delay_us(2000);
			PORTD = 0x10;
			_delay_us(2000);
		}
		PORTD = 0x00;
		_delay_ms(1000);
		for(int x = 0; x < 200; x++)
		{
			PORTD = 0x08;
			_delay_us(2000);
			PORTD = 0x00;
			_delay_us(2000);
		}
		_delay_ms(1000);	
	}
}

