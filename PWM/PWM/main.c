/*
 * PWM.c
 *
 * Created: 2022-07-27 오전 9:50:11
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	/*
		f = 14.7456MHz / 1024 = 14.4kHz
		T = 1/14.4kHz = 0.069444(ms)
	*/
	
	DDRB = 0x10; //PB4 출력
	TCCR0 |= (1 << WGM00) | (1 <<  WGM01);
	TCCR0 |= (1 << COM01);
	TCCR0 |= (1 << CS02) | (1 << CS01) | (1 << CS00);  //TCCR0 = 0b0110111 0x6f;
	TCNT0 = 0;
	OCR0 = 0;
	
	int level = 0;
    /* Replace with your application code */
    while (1) 
    {
		OCR0 = level;
		level++;
		if(level == 255)
			level = 0;
		_delay_ms(10);
    }
}

