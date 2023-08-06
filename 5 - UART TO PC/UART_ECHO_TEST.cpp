/*
 * 4BIT_UART_ECHO_LCD.cpp
 *
 * Created: 7/29/2023 2:12:53 PM
 * Author : B550-E
 * Note: LCD and UART ECHO TEST, What is type on console from pc is sent to avr, shown on lcd and sent back to pc.
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
			for(int j = 0; j <= i; j++)
			{
				transmit(input[j]);
			}
			transmit('\n');
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

