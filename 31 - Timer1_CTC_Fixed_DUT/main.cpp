/*
 * Timer1_CTC_Fixed_DUT.cpp
 *
 * Created: 8/6/2023 7:10:30 PM
 * Author : B550-E
 *
 * TCCR1A: COM1A1 | COM1A0 | COM1B1 | COM1B0 | - | - | WGM11 | WGM10
 * TCCR1B: ICNC1 | ICES1 | - | WGM13 | WGM12 | CS12 | CS11 | CS10
 * TCCR1C: FOC1A | FOC1B | - | - | - | - | - | - |
 * TIFR1: - | - | ICF1 | - | - | OCF1B | OCF1A | TOV1 
 * Variable Duty Cycle Square Wave in both channels. 
 * CTC - Clear Timer on compare match
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

int main(void)
{
	unsigned int a = 12700, b = 12700;
	DDRB = 0x3F;	// Output PB1 and PB2 for OC1A and OC1B 		
	DDRD = 0xF0;	// use PD0 - PD3 as input for pushbuttons 

	while (1)
	{
		if((PIND & 0x01) == 0)	// S1+	Pulse width will increase and freq will decrease
		{
			while((PIND & 0x01) == 0);
			a += 4000;
		}
		if((PIND & 0x02) == 0)	// S1 - Pulse width will decrease and freq will increase
		{
			while((PIND & 0x02) == 0);
			a -= 4000;
		}
		if((PIND & 0x04) == 0);
		{
			while((PIND & 0x04) == 0);
			b += 4000; 
		}
		if((PIND & 0x08) == 0);
		{
			while((PIND & 0x08) == 0);
			b -= 4000;
		}
		TCCR1A = 0xA0;	// com1a1 com1a0 com1b1 com1b0
		TCCR1B = 0x09;	// no Pre-scaler
		TCCR1C = 0x00;
		OCR1A = a;
		OCR1B = a; 
		while((TIFR1 & 0x06) == 0);
		TIFR1 = 0x06;
		TCCR1A = 0xF0;
		TCCR1B = 0x09;
		TCCR1C = 0x00;
		OCR1A = b;
		OCR1B = b;
		while((TIFR1 * 0x06) == 0);
		TIFR1 = 0x06;
	}
}