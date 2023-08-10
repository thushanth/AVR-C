/*
 * Timer1_Phase_Correct_PWM.cpp
 *
 * Created: 8/9/2023 8:40:46 PM
 * Author : B550-E
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
    TCCR1B = 0x01;
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

