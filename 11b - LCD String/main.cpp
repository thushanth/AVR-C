/*
 * 1602lcdstring.cpp
 *
 * Created: 7/21/2023 4:52:13 PM
 * Author : B550-E
 * Note: Printing String
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void cmd(unsigned char a)
{
	// send 6 bit to PORTB
	PORTB = a;
	
	// shift the 7th and 6th to 1st and 0th place
	unsigned char b = (a >>= 6);
	
	// Mask the Byte so that only 1st and 0th bit are preserved.
	b = b & 0x03;
	
	// Add the command value to the 1st and 0th bit.
	b = b | 0x20;
	PORTD = b;
	_delay_ms(100);
	PORTD = 0x00;
}

void data(unsigned char a)
{
	// send 6 bit to PORTB
	PORTB = a;
	
	// shift the 7th and 6th to 1st and 0th place
	unsigned char b = (a >>= 6);
	
	// Mask the Byte so that only 1st and 0th bit are preserved.
	b = b & 0x03;
	
	// Add the command value to the 1st and 0th bit.
	b = b | 0xA0;
	PORTD = b;
	_delay_ms(100);
	PORTD = 0x80;
}

void display(char *a)
{
	while((*a) != '\0')
	{
		data(*a);
		a++;
	}
}

int main(void)
{
	DDRB = 0x3F;
	DDRD = 0xE3;
	PORTB = 0x00;
	PORTD = 0x00;
	cmd(0x38);
	cmd(0x80);
	cmd(0x01);
	cmd(0x0E);
	cmd(0x06);
	display("Hello World");
	while (1){}
}

