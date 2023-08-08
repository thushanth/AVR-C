/*
 * Timer1_Input_Capture.cpp
 *
 * Created: 8/7/2023 2:10:16 PM
 * Author : B550-E
 * TCCR1A: COM1A1 | COM1A0 | COM1B1 | COM1B0 | - | - | WGM11 | WGM10
 * TCCR1B: ICNC1 | ICES1 | - | WGM13 | WGM12 | CS12 | CS11 | CS10
 * TCCR1C: FOC1A | FOC1B | - | - | - | - | - | - |
 * TIFR1: - | - | ICF1 | - | - | OCF1B | OCF1A | TOV1
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void transmit(char a)
{
	UDR0 = a;
	while((UCSR0A & 0x40) == 0);
	_delay_ms(5);
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
    char buf[30] = {'\0'};
	/* Port Settings */
	DDRD = 0x02;
	DDRB = 0x00;
	PORTB = 0x01;
	PORTD = 0x00;
	/* UART Settings */
	UCSR0A = 0x00;
	UCSR0B = 0x18; //Enable Rx Interrupt and Rx enable
	UCSR0C = 0x06; //UMSEL1 UMSEL0 for async USART. USBSn 1 stop bit. UCSZ2 from B and UCSZ1-0 8-bit TX on Rising, RX on Falling
	UBRR0H = 0x00;
	UBRR0L = 0x67; //from table 20-7 9600 bps 103 to hex is 67. on 16MHZ Crystal
	/* Timer Setting */
	TCCR1A = 0x00;
	TCCR1B = 0x41;
	TIFR1 = 0x20;
    while (1) 
    {
		while((TIFR1 & 0x20) == 0);
		TIFR1 = 0x20;
		sprintf(buf, "Event Captured At: %05u\r\n", ICR1);
		serialPrint(buf);
    }
}

