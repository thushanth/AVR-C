/*
 * Internal_EEPROM.cpp
 *
 * Created: 7/31/2023 1:08:48 AM
 * Author : B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <string.h>
#include <stdlib.h>

void cmd(char a)
{
	PORTD = a;
	PORTB = 0x02;
	_delay_ms(100);
	PORTB = 0x00;
}

void data(char a)
{
	PORTD = a;
	PORTB = 0x0A;
	_delay_ms(100);
	PORTB = 0x08;
}

void serialPrint(char *a)
{
	while((*a) != '\0')
	{
		data(*a);
		a++;
	}
}

void lcd_init()
{
	cmd(0x38); cmd(0x01);
	cmd(0x0E); cmd(0x80);	
}

int main(void)
{
	char R_array[16] = {'\0'}, W_array[16] = "Test";
	float k = 0;
	DDRD = 0xFF; DDRB = 0x0F;
	PORTD = 0x00; PORTB = 0x00;
	lcd_init();
	eeprom_busy_wait();
	eeprom_write_byte((uint8_t *)64, (uint8_t)0x55);
	eeprom_write_byte((uint8_t *)48, (uint8_t)0x54);
	eeprom_write_byte((uint8_t *)19, (uint8_t)0x4F);
	
	data(eeprom_read_byte((const uint8_t *)19));
	data(eeprom_read_byte((const uint8_t *)64));
	data(eeprom_read_byte((const uint8_t *)48));		
	
	memset(R_array, '\0', 16*sizeof(char));
	eeprom_busy_wait();
	cmd(0xC0);
	
	eeprom_write_block(W_array, 0, strlen(W_array));
	eeprom_read_block(R_array, (const void *)0, strlen(W_array));
	serialPrint(R_array);
	cmd(0x80);
	cmd(0x01);
	
	eeprom_write_float((float *)28,852.317);
	k = eeprom_read_float((const float *) 28);
	dtostrf((double)k,6,3,R_array);
	serialPrint(R_array);
    while (1){}
}

