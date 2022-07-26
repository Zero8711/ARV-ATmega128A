/*
 * Switch.c
 *
 * Created: 2022-07-26 오전 9:24:57
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRE = 0xFF; //LED output
	DDRD = 0x00; //Switch input
    while (1) 
    {
		PORTE = PIND;
    }
}

