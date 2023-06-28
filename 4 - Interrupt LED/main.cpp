/*
 * InterruptPB.cpp
 *
 * Created: 6/28/2023 12:17:33 PM
 * Author : B550-E
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)	// flash the first LED 
{
	PORTB ^= 0x01;
	EIFR  |= (1<<0);	// reset flag, by writing 1. Can be reset automatically. 
	_delay_ms(200);	
}

ISR(INT1_vect) // flash the second LED
{
	PORTB ^= 0x02;
	EIFR  |= (1<<1);
	_delay_ms(200);
}

int main(void)
{
	DDRD = 0xf3; //pin 2 and pin 3 for interrupt pb
	DDRB = 0x23; //pin 8, pin 9 and pin 13 for led output
	PORTD = 0x00;
	PORTB = 0x00;
	EICRA = 0x00; //INT1 and INT0 as Low Level Interrupt Request
	EIMSK = 0x03; //enable INT1 and INT0
	sei();
    while (1) 
    {
		PORTB ^= (1<<5);
		_delay_ms(1000);
    }
}

