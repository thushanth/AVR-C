/*
 * RELAY_LED.cpp
 *
 * Created: 7/1/2023 3:24:17 PM
 * Author: B550-E
 * Note: Waiting for module to array to test with DC Motor. 
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0x04;
	PORTD = 0x00;
    while (1) 
    {
			PORTD ^= 0x04;
			_delay_ms(1000);
    }
}

