/*
 * Push Button.c
 *
 * Created: 2022-07-26 오전 9:52:49
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

//푸시버튼을 이용하여 LED제어하기
int main(void)
{
	/* Replace with your application code */
	DDRE = 0x0F; //0b0000(버튼)0000(LED)
	//	DDRD = 0x00; //Switch input
	while (1)
	{
		PORTE = (PINE & 0xf0) >> 4; //입력4비트를 하위4비트로 밀어줘서 LED제어
	}
}
