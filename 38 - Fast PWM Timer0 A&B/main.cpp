/*
 * Timer1_fast_pwm.cpp
 *
 * Created: 8/9/2023 8:13:47 PM
 * Author : B550-E
 * TCCR1A = COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
 * TCCR1B = ICNC1 ICES1 - WGM13 WGM12 CS12 CS11 CS10
 * 
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

int main(void)
{
    DDRB = 0x06;
	DDRD = 0x00;
	TCCR1A = 0xA3;
	TCCR1B = 0x09;
	OCR1A = 512;
	OCR1B = 512;
    while (1) 
    {
		if((PIND & 0x01) == 0)
		{
			while((PIND & 0x01) == 0);
			OCR1A += 100;
			OCR1B += 50;	
		}
		if((PIND & 0x02) == 0)
		{
			while((PIND & 0x02) == 0);
			OCR1A -= 100;
			OCR1B -= 50;			
		}
    }
}

