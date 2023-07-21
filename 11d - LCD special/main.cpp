/*
 * LCD1602_Special_char_d.cpp
 *
 * Created: 7/21/2023 6:47:35 PM
 * Author : B550-E
 */ 
/*
 * LCD Scroll.cpp
 *
 * Created: 7/21/2023 5:43:33 PM
 * Author : Manaskant Mishra, Modified: B550-E
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void cmd(unsigned char a)
{
	// send 6 bit to PORTB
	PORTB = a;
	
	// shift the 7th and 6th to 1st and 0th place
	unsigned char b = (a >>= 6);
	
	// Mask the Byte so that only 1st and 0th bit are preserved.
	b = b & 0x03;
	
	// Add the command value to the 1st and 0th bit.
	b = b | 0x20;
	PORTD = b;
	_delay_ms(100);
	PORTD = 0x00;
}

void data(unsigned char a)
{
	// send 6 bit to PORTB
	PORTB = a;
	
	// shift the 7th and 6th to 1st and 0th place
	unsigned char b = (a >>= 6);
	
	// Mask the Byte so that only 1st and 0th bit are preserved.
	b = b & 0x03;
	
	// Add the command value to the 1st and 0th bit.
	b = b | 0xA0;
	PORTD = b;
	_delay_ms(100);
	PORTD = 0x80;
}

void display(char *a)
{
	while((*a) != '\0')
	{
		data(*a);
		a++;
	}
}

void LCD_init()
{
	cmd(0x38);
	cmd(0x80);
	cmd(0x01);
	cmd(0x0E);
	cmd(0x06);
}

void LCD_cust_character()
{
	cmd(0x48);
	data(0x00);
	data(0x0A);
	data(0x15);
	data(0x11);
	data(0x12);
	data(0x04);
	data(0x00);
	data(0x00);
	cmd(0x80);
	data(0x01);
	_delay_ms(10);
	
	cmd(0x50);
	data(0x00); 
	data(0x00);
	data(0x0A);
	data(0x00);
	data(0x04);
	data(0x00);
	data(0x0E);
	data(0x11);
	cmd(0x82);
	data(0x02);
	_delay_ms(10);
	
	cmd(0x58);
	data(0x01);
	data(0x03);
	data(0x05);
	data(0x09);
	data(0x09);
	data(0x0B);
	data(0x1B);
	data(0x18);
	cmd(0x84);
	data(0x03);
	_delay_ms(10);
}

int main(void)
{
	DDRB = 0x3F;
	DDRD = 0xFB;
	PORTB = 0x00;
	PORTD = 0x18;
	LCD_init();
	LCD_cust_character();
	while (1){};
}


