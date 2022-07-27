/*
 * ATmega test.c
 *
 * Created: 2022-07-27 오후 2:06:02
 * Author : KangHyeonGu
 */ 
#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int t_cnt = 0;
int m_cnt = 0;
unsigned char font[] = {0x3f, 0x06, 0x5b, 0x4f,
						0x66, 0x6d, 0x7d, 0x07,
						0x7f, 0x6f, 0x77, 0x7c,
						0x39, 0x5e, 0x79, 0x71,
						0x08, 0x80};// 1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, c, d, e, f, ., _);
			
void segment(unsigned char n)
{
	int buff;
	unsigned char N1000, N100, N10, N1;
	
	N1000 = n / 1000;
	buff = n % 1000;
	N100 = buff / 100;
	buff = buff % 100;
	N10 = buff / 10;
	N1 = buff % 10;
	
	for(int i = 0; i < 30; i++)
	{
		PORTC = 0x0e;
		PORTA = font[N1000];
		_delay_ms(1);
		
		PORTC = 0x0d;
		PORTA = font[N100];
		_delay_ms(1);
		
		PORTC = 0x0b;
		PORTA = font[N10];
		_delay_ms(1);
		
		PORTC = 0x07;
		PORTA = font[N1];
		_delay_ms(1);
	}
}
ISR(TIMER2_COMP_vect)
{
	t_cnt++;
	if(t_cnt >= 100)
	{
		t_cnt = 0;
		m_cnt ++;
	}
}

int main(void)
{
	DDRA = 0xFF;
	DDRC = 0x0F;
	DDRB = 0x80;
	
	PORTA = 0xFF;
	PORTC = 0x0F;
	PORTB = 0x00;
	
	TCCR2 |= (1 << WGM21);
	TCCR2 |= (1 << COM20);
	TCCR2 |= (1 << CS22) | (1 << CS20);
	
	TIMSK |= (1 << OCIE2);
	
	OCR2 = 144; //10ms주기
	
	sei();
	while(1)
	{
		segment(m_cnt);
	}
}