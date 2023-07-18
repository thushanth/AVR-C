/*
 * DOT_Matrix.cpp
 *
 * Created: 7/5/2023 9:01:04 PM
 * This method requires understanding and schematic of the DOT MATRIX. BASED ON 1088AS.
 * Uses the 8x8 Common Cathode pin out. Pin 16 and Pin 1 with multimeter will light up using continuity from DMM. If 16 is + and 1 is GND (Common Cathode), if opposite (Common Anode)
 * See pin out from source: http://acoptex.com/uploads/BxCommonanode.jpg
 * Modified: 7/18/2023 6:59:00 PM
 * Swap Row and Column Wiring, Removed 1, 2 example function and added scan_matrix. 
 * Author : B550-E
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define delay 100
#define scan 5
#define interval 3000

void off()
{
	PORTD = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	_delay_ms(delay);
}

void on()
{
	PORTD = 0x00;
	PORTB = 0xFF;
	PORTC = 0xFF;
	_delay_ms(delay);
}

void scan_matrix()
{
	PORTB = 0x01;
	PORTC = 0x00;
	unsigned char row[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
	unsigned char col2[2] = {0x01, 0x02};
	unsigned char col1[6] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20};
	for(unsigned char i = 0; i < 6; i++)	// Column
	{
		PORTB = col1[i];
		_delay_ms(50);
		for(unsigned char l = 0; l < 8; l++)
		{
			PORTD = row[l];
			_delay_ms(interval/2);
		}
	}
	PORTB = 0x00;
	_delay_ms(50);
	for(unsigned char j = 0; j < 2; j++)
	{
		PORTC = col2[j];
		_delay_ms(50);
		for(unsigned char l = 0; l < 8; l++)
		{
			PORTD = row[l];
			_delay_ms(interval/2);
		}
	}
}

int main(void)
{ 
	// Set Pin Direction as Input or Output
	DDRD = 0xFF;	// ROW D0 - D7
	DDRB = 0x3F;	// COLUMN B0 - B5 
	DDRC = 0x03;	// COLUMN C0 & C1
	_delay_ms(delay);
	
    while (1) 
    {
		off();
		_delay_ms(interval);
		on();
		_delay_ms(interval);
		scan_matrix();
		_delay_ms(interval);
    }
}

