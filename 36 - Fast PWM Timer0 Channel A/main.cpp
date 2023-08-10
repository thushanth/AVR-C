/*
 * fast_pwm_timer0.cpp
 *
 * Created: 8/8/2023 8:44:18 PM
 * Author : B550-E
 */ 

#ifdef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

int main(void)
{
	int i = 127;
	DDRD = 0x40;
	DDRB = 0x00;
	PORTD &= 0x00;
	TCCR0A = 0x83;
	TCCR0B = 0x01;
	OCR0A = i;
    while (1) 
    {
		if((PINB & 0x01) == 0)
		{
			while((PINB & 0x01) == 0);
			OCR0A += 13;
		}
		if((PINB & 0x02) == 0)
		{
			while((PINB & 0x02) == 0);
			OCR0A -= 13;
		}
    }
}

