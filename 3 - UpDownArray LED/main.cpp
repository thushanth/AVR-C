/*
 * Up_Down_LED_Array.cpp
 *
 * Created: 6/27/2023 12:05:43 PM
 * Modified: 6/30/2023 5:54:26 PM
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
	char index[8] = {0x01,0x03,0x07,0x0f,0x1f,0x3f, 0x7f,0xff}; // Easier to make states for the PORT rather than using math function
	int i = 0;
	DDRD = 0xff;	// Set PORT D as output Digital Pin 0 - 7
	DDRB = 0x00;	// Set  PORT B as input, using only pin 8 and 9 for PB
	PORTD = 0x00;	// Set all output on PORT D as logic low
	_delay_ms(100);
	while (1) 
	{
		if(i > 8 || i < 0)	// try
		{
			PORTD = 0x00;
			_delay_ms(delay);
			i = 0;	
		}
		else // catch
		{
			if((PINB & 0x01)==0)	// Alt: if((PINB & (1 << PINB0)) == 0) if logic low on digital 8, pull-up resistor
			{
				while((PINB & 0x01) ==0);	//while((PINB & (1 << PINB0)) == 0), stay in loop until de-pressed
				PORTD = index[i];
				i++;
				_delay_ms(delay);
			}
			if((PINB & 0x02)==0)	// Alt: if((PINB & (1 << PINB1)) == 0) if logic low on digital 9
			{
				while((PINB & 0x02) ==0);	//while((PINB & (1 << PINB1)) == 0), stay in loop until de-pressed
				i--;
				PORTD = index[i];
				_delay_ms(delay);
			}
		}
	}
}
