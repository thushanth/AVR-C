/*
 * Input Capture Timer1.cpp
 *
 * Created: 8/6/2023 7:17:33 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
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
	char buf[30] = {'\0'};
	char obuf[30];
	unsigned long t1 = 0, t2 = 0, t = 0, i = 0;
	float t_sec = 0.0;
	DDRD = 0x02;
	DDRB = 0x00;	// ICP1
	PORTB = 0x0F;	// Pull-up
	PORTD = 0x00;
	UCSR0A = 0x00;
	UCSR0B = 0x18; // Enable Rx Interrupt and Rx enable
	UCSR0C = 0x06; // UMSEL1 UMSEL0 for async USART. USBSn 1 stop bit. UCSZ2 from B and UCSZ1-0 8-bit TX on Rising, RX on Falling
	UBRR0H = 0x00;
	UBRR0L = 0x67; // from table 20-7 9600 bps 103 to hex is 67. on 16MHZ Crystal
	TCCR1A = 0x00; //
	TCCR1B = 0x43; // Rising Edge, 64 prescaler
	TIFR1 = 0x20; // ICF1 flag
    while (1) 
    {
		while((TIFR1 & 0x20) == 0);
		t1 = ICR1;
		TIFR1 = 0x20;
		
		while((TIFR1 & 0x20) == 0);
		{
			if(TCNT1 >= 65535)
			{
				i++;
			}
		}
		t2 = ICR1;
		TIFR1 = 0x20;
		
		t = (65535 - t1) + ((i - 1) * 65535) + t2;
		t_sec = 0.000008 * (float)t / 5.2;
		
		dtostrf(t_sec, 4, 2, obuf);
		sprintf(buf, "Time Measured = %s ms\r\n", obuf);
		serialPrint(buf);
		i=0;
    }
}

