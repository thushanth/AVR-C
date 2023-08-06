/*
 * 4BIT_UART_LCD.cpp
 *
 * Created: 7/28/2023 7:42:57 PM
 * Author : B550-E
 * Note: LCD is in 4-bit Mode and uses UART FTDI, User will see on com port the phrase Test to Serial and from serial they can type a phrase max 16 characters back to the AVR to be shown on the LCD second row.
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/* Serial Configuration and Functions */

void serialSetup()
{
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 0x67;
}

char receive()
{
	while((UCSR0A & 0x80) == 0);
	return UDR0;
}

void transmit(char a)
{
	UDR0 = a;
	while((UCSR0A & 0x40) == 0);
	_delay_ms(100);
}

void serialPrint(char *a)
{
	while((*a) != '\0')
	{
		transmit(*a);
		a++;
	}
}

/* LCD Configurations and Functions */

void cmd(char a)
{
	PORTD = (a & 0xF0);
	PORTB = 0x02;
	_delay_ms(100);
	PORTB = 0x00;
	
	PORTD = ((a<<4) & 0xF0);
	PORTB = 0x02;
	_delay_ms(100);
	PORTB = 0x00;
}

void data(char a)
{
	PORTD = (a & 0xF0);
	PORTB = 0x0A;
	_delay_ms(100);
	PORTB = 0x08;
	
	PORTD = ((a<<4) & 0xF0);
	PORTB = 0x0A;
	_delay_ms(100);
	PORTB = 0x08;
}

void lcdPrint(char *a)
{
	while((*a) != '\0')
	{
		data(*a);
		a++;
	}
}

void lcdSetup()
{
	cmd(0x02);
	cmd(0x28);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);
}

int main(void)
{
	char a;
	char input[16];
	int i = 0;
	
	// Setup Pin for Input for LCD RS/RW/E
	// Setup Pin for Input for LCD D4-D7 
	DDRB = 0x0F; DDRD = 0xF2;
	PORTB = 0x00; PORTD = 0x00;
	
	// Setup BaudRate
	serialSetup();
	serialPrint("Test to PC Serial \n \r \0");
	
	// Setup LCD 
	lcdSetup();
	lcdPrint("Test to LCD:");
	
	// Jump to second Line
	cmd(0xC0);
    while(1)
	{
		a = receive();
		if(a == '\n')
		{
			lcdPrint(input);
			i = 0;
			cmd(0xC0);
		}
		else
		{
			input[i] = a;
			i++;
		}
	}
}

