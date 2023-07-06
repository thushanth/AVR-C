/*
 * DOT_Matrix.cpp
 *
 * Created: 7/5/2023 9:01:04 PM
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define delay 100
#define scan 50
#define interval 3000

void off()
{
	PORTD = 0x00;
	_delay_ms(delay);
}

void on()
{
	PORTD = 0xFF;
	_delay_ms(delay);
}
void one()
{
	PORTD = 0x18;
	_delay_ms(delay);
}

void two()
{
	PORTD = 0xFF;
	PORTC = 0xFC;
	PORTB = 0xFF;
	_delay_ms(scan);
	PORTD = 0x70;
	PORTC = 0xFF;
	PORTB = 0xDF;
	_delay_ms(scan);
	PORTD = 0x38;
	PORTC = 0xFF;
	PORTB = 0xEF;
	_delay_ms(scan);
	PORTD = 0x1C;
	PORTC = 0xFF;
	PORTB = 0xF7;
	_delay_ms(scan);	
	PORTD = 0x0E;
	PORTC = 0xFF;
	PORTB = 0xFB;
	_delay_ms(scan);
	PORTD = 0xFF;
	PORTC = 0xFF;
	PORTB = 0xFD;
	_delay_ms(scan);
	PORTD = 0x7E;
	PORTC = 0xFF;
	PORTB = 0xFE;
	_delay_ms(scan);		
}

int main(void)
{
	DDRD = 0xFF;	// COLUMN
	DDRB = 0x3F;	// ROW
	DDRC = 0x03;	// ROW
	
	_delay_ms(delay);
    while (1) 
    {
		//off();
		//_delay_ms(interval);
		//on();
		//_delay_ms(interval);
		//one();
		//_delay_ms(interval);
		//two();
		//_delay_ms(100);
		//_delay_ms(500);
    }
}

