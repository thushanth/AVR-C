/*
 * 4x4_Keypad.cpp
 *
 * Created: 7/21/2023 9:12:07 PM
 * Modified: 7/27/2023 7:02 PM
 * Original Author: Manaskant Mishra - Modified to use LED Matrix instead of LCD, can use LCD 4-bit Mode or UART
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int keypad()
{
	unsigned char k_in = 0xFF; 
	int k_out = 255;
	
	PORTD = 0xEF;
	_delay_us(10);
	k_in = PIND & 0x0F;
	if(k_in == 0x07)
		k_out = 4;
	else if(k_in == 0x0B)
		k_out = 3;
	else if(k_in == 0x0D)
		k_out = 2;
	else if(k_in == 0x0E)
		k_out = 1;
		
	PORTD = 0xDF;
	_delay_us(10);
	k_in = PIND & 0x0F;	
	if(k_in == 0x07)
		k_out = 8;
	else if(k_in == 0x0B)
		k_out = 7;
	else if(k_in == 0x0D)
		k_out = 6;
	else if(k_in == 0x0E)
		k_out = 5;		

	PORTD = 0xBF;
	_delay_us(10);	
	k_in = PIND & 0x0F;	
	if(k_in == 0x07)
		k_out = 12;
	else if(k_in == 0x0B)
		k_out = 11;
	else if(k_in == 0x0D)
		k_out = 10;
	else if(k_in == 0x0E)
		k_out = 9;		

	PORTD = 0x7F;
	_delay_us(10);
	k_in = PIND & 0x0F;		
	if(k_in == 0x07)
		k_out = 16;
	else if(k_in == 0x0B)
		k_out = 15;
	else if(k_in == 0x0D)
		k_out = 14;
	else if(k_in == 0x0E)
		k_out = 13;
		
	return k_out;
}

int main(void)
{
	int k = 255;
	
	DDRB = 0x0F;	// LED - OUTPUT
	DDRD = 0xF0;	// KEYPAD - OUTPUT for ROW PD4 - PD7 and INPUT for Column PD0 - PD3
	_delay_ms(100);
	
	PORTB = 0x0F;	// LED 
	PORTD = 0xFF;   // Initial State all 1
	_delay_ms(300);
	
    while (1) 
    {
		k = keypad();
		if(k != 255)
		{
			switch(k)
			{
				case 1:
				PORTB = 0x01;
				break;
				
				case 2: 
				PORTB = 0x02;
				break;
				
				case 3:
				PORTB = 0x03;
				break;
				
				case 4:
				PORTB = 0x0A;
				break;
							
				case 5:
				PORTB = 0x04;
				break;			
				
				case 6:
				PORTB = 0x05;
				break;		
				
				case 7:
				PORTB = 0x06;
				break;
				
				case 8:
				PORTB = 0x0B;
				break;		
				
				case 9:
				PORTB = 0x07;
				break;
				
				case 10:
				PORTB = 0x08;
				break;		
				
				case 11:
				PORTB = 0x09;
				break;
				
				case 12:
				PORTB = 0x0C;
				break;			
				
				case 13:
				PORTB = 0x0E;
				break;
				
				case 14:
				PORTB = 0x00;
				break;

				case 15:
				PORTB = 0x0F;
				break;
				
				case 16:
				PORTB = 0x0D;
				break;												
			}
		}
		else
		continue;
		
		_delay_ms(300);
    }
}

