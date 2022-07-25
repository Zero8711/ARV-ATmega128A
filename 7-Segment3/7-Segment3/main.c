/*
 * 7-Segment3.c
 *
 * Created: 2022-07-25 오후 4:14:45
 * Author : KCCI17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07,
0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x08, 0x80};

void segment(int n)
{
	unsigned char N1000, N100, N10, N1;
	int buff;
	
	N1000 = n / 1000; //1000의 자리
	buff = n % 1000;
	N100 = buff / 100; //100의 자리
	buff = buff % 100;
	N10 = buff / 10; //10의 자리
	N1 = buff % 10; //1의 자리
	
	for (int i = 0; i < 30; i++)
	{
		PORTG = 0x0e; //1
		PORTB = font[N1000];
		_delay_ms(1);
		
		PORTG = 0x0d; //2
		PORTB = font[N100];
		_delay_ms(1);
		
		PORTG = 0x0b; //3
		PORTB = font[N10];
		_delay_ms(1);
		
		PORTG = 0x07; //4
		PORTB = font[N1];
		_delay_ms(1);
	}
}


int main(void)
{
	/* Replace with your application code */
	DDRB = 0xff;
	DDRG = 0x0f;
	
	int count = 0;
	while(1)
	{
		segment(count);
		count++;
		if(count == 9999)
		{
			count = 0;
		}
	}
	
}

