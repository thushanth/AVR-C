/*
 * variable_dut_cycle.cpp
 *
 * Created: 8/6/2023 5:42:49 PM
 * Author : B550-E
 * 50% Duty Cycle variable, Square Wave Variable frequency
 * use oscilloscope on pin PD6 to see the waveform output. LED will not help here.
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

int main(void)
{
	unsigned int a = 199, b = 199;
    DDRD = 0xC0;	// PD6 uses OC0A if you use PD5, OC0B and need to change OCR0A to OCR0B. 
	DDRB = 0x30;
	PORTB = 0x0F;	//internal pullups
    while (1) 
    {
		if((PINB & 0x01) == 0)	// S1+	off time
		{
			while((PINB & 0x01) == 0);
			a += 10;
		}
		if((PINB & 0x02) == 0)	// S1 - 
		{
			while((PINB & 0x02) == 0);
			a -= 10;
		}
		if((PINB & 0x04) == 0)	// S2 + on Time
		{
			while((PINB & 0x04) == 0);
			b += 10;
		}	
		if((PINB & 0x08) == 0)	// S2 - 
		{
			while((PINB & 0x08) == 0);
			b -= 10;
		}	
		OCR0A = a; // 16MHz/((2*1[prescaler])*200) = 40kHz
		TCCR0A = 0xC2;	// OC0 is split to A and B. PD6 an PD5, COM0A1 COM0A0; Toggle OC0 on compare match
		TCCR0B = 0x01;
		while((TIFR0 & 0x02) == 0);
		TIFR0 = 0x02;	// reset the flag OCF0A by writing a 1.
		OCR0A = b;
		TCCR0A = 0x42;
		TCCR0B = 0x01;
		while((TIFR0 & 0x02) == 0);
		TIFR0 = 0x02;	// reset the flag OCF0A by writing a 1.		
    }
}
