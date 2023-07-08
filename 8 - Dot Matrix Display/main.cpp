/*
 * DOT_Matrix.cpp
 *
 * Created: 7/5/2023 9:01:04 PM
 * This method requires understanding and schematic of the DOT MATRIX. BASED ON 1088AS.
 * Not perfect but for time sake, will revist latter. 
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define delay 100
#define scan 5
#define interval 3000

void off()
{
	PORTD = 0xFF;
	PORTB = 0xFF;
	PORTC = 0xFF;
	_delay_ms(delay);
}

void on()
{
	PORTD = 0xFF;
	PORTB = 0x00;
	PORTC = 0x00;
	_delay_ms(delay);
}
void one()
{
	PORTD = 0x18;
	PORTB = 0x00;
	PORTC = 0x00;
	_delay_ms(delay);
}

void two()
{
	PORTD = 0xFF;
	PORTC = ~0x00;
	PORTB = ~0x03;
	_delay_ms(scan);
	PORTD = 0x70;
	PORTC = ~0x00;	
	PORTB = ~0x04;
	_delay_ms(scan);
	PORTD = 0x38;
	PORTC = ~0x00;
	PORTB = ~0x08;
	_delay_ms(scan);	
	PORTD = 0x1C;
	PORTC = ~0x00;
	PORTB = ~0x10;
	_delay_ms(scan);
	PORTD = 0x0E;
	PORTC = ~0x00;
	PORTB = ~0x20;
	_delay_ms(scan);
	PORTD = 0xFF;
	PORTC = ~0x01;
	PORTB = ~0x00;
	_delay_ms(scan);
	PORTD = 0xFE;
	PORTC = ~0x02;
	PORTB = ~0x00;
	_delay_ms(scan);				
}	

int main(void)
{
	DDRD = 0xFF;	// COLUMN D0 - D7
	DDRB = 0x3F;	// ROW B0 - B5 
	DDRC = 0x03;	// ROW C0 & C1
	
	_delay_ms(delay);
    while (1) 
    {
		off();
		_delay_ms(interval);
		on();
		_delay_ms(interval);
		one();
		_delay_ms(interval);
		two();
		_delay_ms(100);
    }
}

