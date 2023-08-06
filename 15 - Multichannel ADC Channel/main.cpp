/*
 * ADC_MULTI_Channel.cpp
 *
 * Created: 7/29/2023 7:48:51 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

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

int read_adc_channel(char a)
{
	int raw_value = 0;
	ADMUX = 0x60;
	ADMUX |= (a & 0x0F);
	ADCSRA = 0x87;
	ADCSRA |= 0x40;
	while((ADCSRA & 0x40) != 0);
	raw_value = (ADCL >> 6) | (ADCH << 2);
	ADCSRA = 0x00;
	return raw_value;
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
	float adc0 = 0, adc1 = 0;
	char txbuf[25] = {'\0'};
	char buf[6];
	DDRC = 0x00;
	DDRD = 0x02;
	PORTC = 0x00;
	PORTD = 0x00;
	serialSetup();
    while (1) 
    {
		/* Embedded Systems do not support sprintf float values. to fix this use vfprintf with linker https://startingelectronics.org/articles/atmel-AVR-8-bit/print-float-atmel-studio-7/ */
		/* Will require 2k of ram, instead i lost 1k in progmem by adding stdlib library and converting float to string. */
		adc0 = read_adc_channel(0);
		adc0 = (adc0/1023)*5;
		dtostrf(adc0, 4, 2, buf);
		sprintf(txbuf, "ADC_0 Value = %s V ", buf);
		serialPrint(txbuf);
		
		adc1 = read_adc_channel(1);
		adc1 = (adc1/1023)*5;		
		dtostrf(adc1, 4, 2, buf);		
		sprintf(txbuf, "ADC_1 Value = %s V \n", buf);
		serialPrint(txbuf);
    }
}

