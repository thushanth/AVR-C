/*
 * UART_FTDI.cpp
 *
 * Created: 6/28/2023 4:05:23 PM
 * Author : B550-E
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void transmit(char a)
{
	UDR0 = a;
	while((UCSR0A & 0x40) == 0);	//wait for usart transmit flag to reset
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

int main(void)
{
	DDRD = 0x02; // setting TX PIN 1 as output and RX PIN as input
	PORTD = 0x00;
	UCSR0A = 0x00;
	UCSR0B = 0x18; //Enable Rx Interrupt and Rx enable
	UCSR0C = 0x06; //UMSEL1 UMSEL0 for async USART. USBSn 1 stop bit. UCSZ2 from B and UCSZ1-0 8-bit TX on Rising, RX on Falling
	UBRR0H = 0x00; 
	UBRR0L = 0x67; //from table 20-7 9600 bps 103 to hex is 67. on 16MHZ Crystal
/*	transmit('H');
	transmit('E');
	transmit('L');
	transmit('L');
	transmit('O');*/
	serialPrint("Nice to Meet you \n \r \0");
    while (1) 
    {
    }
}

