/*
 * Button_Interrupt2.c
 *
 * Created: 2022-07-26 오전 11:31:52
 * Author : KCCI17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int count = 0;

unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f,
	0x66, 0x6d, 0x7d, 0x07,
	0x7f, 0x6f, 0x77, 0x7c,
	0x39, 0x5e, 0x79, 0x71,
0x08, 0x80};// 1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, c, d, e, f, ., _);

void segment(unsigned char n)
{
	unsigned char n10, n1;
	n10 = n / 10;
	n1 = n % 10;
	
	for(int i = 0; i < 30; i++)
	{
		PORTG = 0x0b;
		PORTB = font[n10];
		_delay_ms(1);
		PORTG = 0x07;
		PORTB = font[n1];
		_delay_ms(1);
	}
}

ISR(INT0_vect)
{
	count++;
}

ISR(INT4_vect)
{
	count--;
}

int main(void)
{
	DDRB = 0xFF;
	DDRG = 0x0F;
	DDRD = 0x00;
	
	EIMSK = ((1 << INT0) | (1 << INT4)); //Interrupt 0, Interrupt 4
	
//	EICRA |= (1 << ISC00) | (1 << ISC01); //Interrupt 0 RISING EDGE
//	EICRB |= (1 << ISC40) | (1 << ISC41); //Interrupt 4 RISING EDGE

	EICRA |= (1 << ISC01); //Interrupt 0 FALLING EDGE
	EICRB |= (1 << ISC41); //Interrupt 4 FALLING EDGE
	//SREG = 0x80;  //sei();
	sei();
	/* Replace with your application code */
	while (1)
	{
		segment(count);
	}
}

