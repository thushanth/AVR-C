/*
 * IR_LED_LINE_FOLLOWING.cpp
 *
 * Created: 7/31/2023 7:12:15 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

/* Serial Configuration and Functions */

void serialSetup()
{
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 0x67;
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


int main(void)
{
    DDRD = 0x02;
	PORTD = 0x00;
	
	serialSetup();
	serialPrint("Test Line following\n");

    while (1) 
    {
		if(!(PIND & (1<<4)))
		{
			serialPrint("L1 is Low\n");
		}
		else if(!(PIND & (1<<5)))
		{
			serialPrint("L2 is Low\n");			
		}
		else if(!(PIND & (1<<6)))
		{
			serialPrint("L3 is Low\n");			
		}
		else if(!(PIND & (1<<7)))
		{
			serialPrint("L4 is Low\n");			
		}
    }
	/* Simple Test, we don't really care about line following at the moment. Can be modified to ensure we are in the line. When covered, the voltage will drop to 0V as the output of the Line following modules. Remove ! for inverse logic*/
}

