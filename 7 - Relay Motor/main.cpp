/*
 * Relay_Motor.cpp
 *
 * Created: 7/5/2023 8:11:55 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define delay 100

int main(void)
{
	DDRD = 0x04;	// SET PIN D2 as output and The rest as inputs
	PORTD = 0x00;
	_delay_ms(delay);
    while (1) 
    {
		if((PIND & 0x80) == 0)	// if D7 is pressed
		{
			while((PIND & 0x80) == 0);	// Wait until D7 is depressed
			PORTD = 0x04;				// Set D2 as High for output
			_delay_ms(5000);			// Run for 5 seconds
		}
		PORTD = 0x00;					// Always set D2 as low.
		_delay_ms(delay);
    }
}

