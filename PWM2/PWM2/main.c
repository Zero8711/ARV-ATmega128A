/*
 * PWM.c
 *
 * Created: 2022-07-27 오전 10:29:21
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char r_tcnt = 0, r_mcnt = 0;
unsigned char l_tcnt = 0, l_mcnt = 0;

unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f,
						0x66, 0x6d, 0x7d, 0x07,
						0x7f, 0x6f, 0x77, 0x7c,
						0x39, 0x5e, 0x79, 0x71,
						0x08, 0x80};// 1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, c, d, e, f, ., _);

ISR(TIMER0_COMP_vect)
{
	l_tcnt++;
	if(l_tcnt >= 28)
	{
		l_tcnt = 0;
		l_mcnt++;
		if(l_mcnt >= 99)
		l_mcnt = 0;
	}
}

ISR(TIMER0_OVF_vect)
{
	r_tcnt++;
	if(r_tcnt >= 56)
	{
		r_tcnt = 0;
		r_mcnt++;
		if(r_mcnt >= 99)
		r_mcnt = 0;
	}
}

void l_segment(unsigned char n)
{
	unsigned char n10, n1;
	n10 = n /10;
	n1 = n % 10;
	
	for(int i = 0 ;i < 5 ; i++)
	{
		PORTC = 0x0e;
		PORTA = font[n10];
		_delay_ms(1);
		PORTC = 0x0d;
		PORTA = font[n1];
		_delay_ms(1);
	}
}

void r_segment(unsigned char n)
{
	unsigned char n10, n1;
	n10 = n / 10;
	n1 = n % 10;
	
	for(int i = 0 ;i < 5 ; i++)
	{
		PORTC = 0x0b;
		PORTA = font[n10];
		_delay_ms(1);
		PORTC = 0x07;
		PORTA = font[n1];
		_delay_ms(1);
	}
}

int main(void)
{
	DDRB = 0x10; // OC0인 PB4 설정
	DDRA = 0xff;
	DDRC = 0x0f;
	
	PORTA = 0xff;
	PORTC = 0x0f;

	TIMSK |= (1<<OCIE0) | (1<<TOIE0);
	TCCR0 |= (1<<WGM00) | (1<<WGM01); // Fast PWM Mode
	TCCR0 |= (1<<COM01); // set OC0 at BOTTOM
	TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02); // prescaler 1024
	//TCNT0 = 0;
	OCR0 = 102; // PWM 40%
	sei();
	/* Replace with your application code */
	while (1)
	{
		r_segment(r_mcnt);
		l_segment(l_mcnt);
	}
}
