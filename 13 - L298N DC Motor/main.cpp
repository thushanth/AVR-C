/*
 * L298N_DC_MOTOR.cpp
 *
 * Created: 7/28/2023 6:33:03 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xF0;	//D7 and D6
	PORTD = 0x00;
    while(1) 
    {
		PORTD = 0x80;		//	FWD
		_delay_ms(5000);
		PORTD = 0x40;		//	RWD
		_delay_ms(5000);
		PORTD = 0x00;
		_delay_ms(5000);	// Halt
    }
}

