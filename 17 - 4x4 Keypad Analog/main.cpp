/*
 * 4x4_KEYPAD_ADC.cpp
 *
 * Created: 7/30/2023 2:35:18 PM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define btn0 (val >= 247) && (val <= 253)
#define btn1 (val >= 124) && (val <= 128)
#define btn2 (val >= 80) && (val <= 86)
#define btn3 (val >= 57) && (val <= 62)
#define btn4 (val >= 289) && (val <= 296)
#define btn5 (val >= 133) && (val <= 138)
#define btn6 (val >= 87) && (val <= 90)
#define btn7 (val >= 64) && (val <= 67)
#define btn8 (val >= 410) && (val <= 422)
#define btn9 (val >= 157) && (val <= 161)
#define btn10 (val >= 96) && (val <= 100)
#define btn11 (val >= 68) && (val <= 72)
#define btn12 (val >= 524) && (val <= 536)
#define btn13 (val >= 169) && (val <= 177)
#define btn14 (val >= 104) && (val <= 109)
#define btn15 (val >= 73) && (val <= 76)



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

void adc_init()
{
	ADMUX = 0x60;
	ADCSRA = 0x87;
}

void keypad(int val)
{
	if(btn0)
		serialPrint("1\r\n");
	else if(btn1)
		serialPrint("2\r\n");
	else if(btn2)
		serialPrint("3\r\n");
	else if(btn3)
		serialPrint("A\r\n");
	else if(btn4)
		serialPrint("4\r\n");
	else if(btn5)
		serialPrint("5\r\n");
	else if(btn6)
		serialPrint("6\r\n");
	else if(btn7)
		serialPrint("B\r\n");
	else if(btn8)
		serialPrint("7\r\n");
	else if(btn9)
		serialPrint("8\r\n");
	else if(btn10)
		serialPrint("9\r\n");
	else if(btn11)
		serialPrint("C\r\n");
	else if(btn12)
		serialPrint("*\r\n");
	else if(btn13)
		serialPrint("0\r\n");
	else if(btn14)
		serialPrint("#\r\n");
	else if(btn15)
		serialPrint("D\r\n");
}

int main(void)
{
	DDRD = 0x02;
	PORTD = 0x00;
	DDRC = 0x00;
	PORTC = 0x00;
	
	int rv_adc = 0;
	char tx_buf[10] = {'\0'};

	adc_init();
	serialSetup();
	serialPrint("TEST ADC");

    while (1) 
    {
		ADCSRA |= 0x40;
		while((ADCSRA & 0x40) != 0);
		rv_adc = (ADCL >> 6) | (ADCH << 2);
		//sprintf(tx_buf, "%d\r\n", rv_adc);	// uncomment this and serialPrint function below to see ADC value
		if(rv_adc == 0)
		{
			// Ignore 0 read from adc.
		}
		else
		{
			/*serialPrint(tx_buf);
			for(int i = 0; i<10; i++)
			{
				tx_buf[i] = '\0';
			}*/
			keypad(rv_adc);
		}
		_delay_ms(180);
    }
}

