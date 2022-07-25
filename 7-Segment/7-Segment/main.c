/*
 * 7-Segment.c
 *
 * Created: 2022-07-25 오후 3:37:36
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07,
						0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x08, 0x80};//1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, c, d, e, f, ., _)


int main(void)
{
    /* Replace with your application code */
	DDRB = 0xff;
	DDRG = 0x0f;
	PORTG = 0x00;
	
	int num = 0;
    while (1) 
    {
		PORTB = font[num];
		num++;
		_delay_ms(1000);
		if(PORTB == 0x80)
		{
			num = 0;
		}
    }
}

