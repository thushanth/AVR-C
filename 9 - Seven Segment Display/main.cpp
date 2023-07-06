/*
 * SSD_LED.cpp
 *
 * Created: 7/5/2023 11:55:28 PM
 * Author : B550-E
 * Code can be simplified with array of address of functions. Designed for common anode. 
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void zero()
{	// .GFE DCBA
	PORTD = ~0x3F;
	_delay_ms(100);
}

void one()
{
	PORTD = ~0x06;
	_delay_ms(100);	
}

void two()
{
	PORTD = ~0x5B;
	_delay_ms(100);	
}

void three()
{
	PORTD = ~0x4F;
	_delay_ms(100);	
}

void four()
{
	PORTD = ~0x66;
	_delay_ms(100);	
}

void five()
{
	PORTD = ~0x6D;
	_delay_ms(100);	
}

void six()
{
	PORTD = ~0x7D;
	_delay_ms(100);	
}

void seven()
{
	PORTD = ~0x07;
	_delay_ms(100);	
}

void eigth()
{
	PORTD = ~0x7F;
	_delay_ms(100);	
}

void nine()
{
	PORTD = ~0x67;
	_delay_ms(100);	
}

void a()
{
	PORTD = ~0x77;
	_delay_ms(100);	
}

void b()
{
	PORTD = ~0x7C;
	_delay_ms(100);	
}

void c()
{
	PORTD = ~0x58;
	_delay_ms(100);	
}

void d()
{
	PORTD = ~0x5E;
	_delay_ms(100);	
}

void e()
{
	PORTD = ~0x79;
	_delay_ms(100);	
}

void f()
{
	PORTD = ~0x71;
	_delay_ms(100);	
}

void dot()
{
	PORTD &= ~0x80;
	_delay_ms(100);	
}

void dash()
{
	PORTD = ~0x40;
	_delay_ms(100);	
}

void increment()
{
	zero();
	_delay_ms(1000);
	one();
	_delay_ms(1000);
	two();
	_delay_ms(1000);
	three();
	_delay_ms(1000);
	four();
	_delay_ms(1000);
	five();
	_delay_ms(1000);
	six();
	_delay_ms(1000);
	seven();
	_delay_ms(1000);
	eigth();
	_delay_ms(1000);
	nine();
	_delay_ms(1000);

	a();
	_delay_ms(1000);
	b();
	_delay_ms(1000);
	c();
	_delay_ms(1000);	
	d();
	_delay_ms(1000);	
	e();
	_delay_ms(1000);
	f();
	_delay_ms(1000);
	dot();
	_delay_ms(1000);
	dash();
	_delay_ms(1000);
}

int main(void)
{
    DDRD = 0xFF;	// The characters
	DDRB = 0xFF;	// The Digit Control
	_delay_ms(100);
    while (1) 
    {
		PORTB = 0x01;	// set the first digit
		_delay_ms(100);
		increment();
		PORTB = 0x02;
		_delay_ms(100);
		increment();
		PORTB = 0x04;
		_delay_ms(100);
		increment();
    }
}

