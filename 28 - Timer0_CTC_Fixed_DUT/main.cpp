/*
 * Timer0_CTC_Mode.cpp
 *
 * Created: 8/2/2023 12:36:29 AM
 * Author : B550-E
 * 50% Duty Cycle fixed, Square Wave Variable frequency
 * use oscilloscope on pin PD6 to see the waveform output. LED will not help here.
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>


int main(void)
{
    DDRD = 0xC0;	// PD6 uses OC0A if you use PD5, OC0B and need to change OCR0A to OCR0B. 
	DDRB = 0x3C;
	TCCR0A = 0x42;	// OC0 is split to A and B. PD6 an PD5, COM0A1 COM0A0; Toggle OC0 on compare match
	TCCR0B = 0x01;
	OCR0A = 199;	// 16MHz/((2*1[prescaler])*200) = 40kHz
    while (1) 
    {
		if((PINB & 0x01) == 0)	// S1+	Pulse width will increase and freq will decrease
		{
			while((PINB & 0x01) == 0);
			OCR0A += 10;
		}
		if((PINB & 0x02) == 0)	// S1 - Pulse width will decrease and freq will increase
		{
			while((PINB & 0x02) == 0);
			OCR0A -= 10;
		}
    }
}

