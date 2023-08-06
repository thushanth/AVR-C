/*
 * analog_LDR.cpp
 *
 * Created: 7/31/2023 1:54:41 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

/* LCD Configurations and Functions */

void cmd(char a)
{
	PORTD = (a & 0xF0);
	PORTB = 0x02;
	_delay_ms(100);
	PORTB = 0x00;
	
	PORTD = ((a<<4) & 0xF0);
	PORTB = 0x02;
	_delay_ms(100);
	PORTB = 0x00;
}

void data(char a)
{
	PORTD = (a & 0xF0);
	PORTB = 0x0A;
	_delay_ms(100);
	PORTB = 0x08;
	
	PORTD = ((a<<4) & 0xF0);
	PORTB = 0x0A;
	_delay_ms(100);
	PORTB = 0x08;
}

void lcdPrint(char *a)
{
	while((*a) != '\0')
	{
		data(*a);
		a++;
	}
}

void lcdSetup()
{
	cmd(0x02);
	cmd(0x28);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x80);
}


int main(void)
{
	int raw_adc = 0, volt;
	double mvolt_adc = 0.0;


	DDRB = 0x0F;
	DDRD = 0xF0;
	DDRC = 0x00;
	PORTB = 0x00;
	PORTD = 0x00;
	PORTC = 0x00;

	ADMUX = 0x60;	// ADC MUX ADC0 at single Ended Input
	ADCSRA = 0x87;	// sampling rate 16MHz/128 = 125KHz
	
	lcdSetup(); 
    while (1) 
    {
		ADCSRA |= 0x40;					// START ADC Conversion Step
		while((ADCSRA & 0x40) != 0);
		
		raw_adc = (ADCL >> 6) | (ADCH <<2);
		
		mvolt_adc = (raw_adc * 5) / 1023.0;
		volt = mvolt_adc * 1000;
		
		lcdPrint("Raw Out: ");
		data((raw_adc/1000) + 48);
		data(((raw_adc/100) % 10) + 48);
		data(((raw_adc/10) % 10) + 48 );
		data((raw_adc % 10) + 48);
		cmd(0x80);
		cmd(0xC0);
		
		lcdPrint("Volts: ");
		data((volt/1000) + 48); data('.');
		data(((volt/100) % 10) + 48);
		data(((volt/10) % 10) + 48 );
		data((volt % 10) + 48);
		lcdPrint(" V  ");
		cmd(0xC0);
		cmd(0x80);		
    }
}

