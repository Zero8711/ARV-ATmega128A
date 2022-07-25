/*
 * 7-Segment2.c
 *
 * Created: 2022-07-25 오후 4:08:36
 * Author : KCCI17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07,
0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x08, 0x80};// 1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, c, d, e, f, ., _);


int main(void)
{
	/* Replace with your application code */
	DDRB = 0xff;
	DDRG = 0x0f;
	PORTG = 0x00;
	
	while(1)
	{
		PORTG = 0x0e; //1
		PORTB = font[1];
		_delay_ms(1);
		
		PORTG = 0x0d; //2
		PORTB = font[2];
		_delay_ms(1);
		
		PORTG = 0x0b; //3
		PORTB = font[3];
		_delay_ms(1);
		
		PORTG = 0x07; //4
		PORTB = font[4];
		_delay_ms(1);
	}
	
}



