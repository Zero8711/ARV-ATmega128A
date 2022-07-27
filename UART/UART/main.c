/*
 * UART.c
 *
 * Created: 2022-07-27 오전 11:51:05
 * Author : KangHyeonGu
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

void UART0_transmit(char data);
uint8_t UART0_receive(void);

void UART0_transmit(char data)
{
	while(!(UCSR0A & (1 << UDRE0)));
	//비어있는 상태 1 & 1 = 1 -> 0
	UDR0 = data;
}

uint8_t UART0_receive(void)
{
	while(!(UCSR0A & (1 << RXC1)));
	return UDR0;
}

int main(void)
{
	DDRE = 0xFE;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = 0x06;
	UBRR0L = 95;
    /* Replace with your application code */
    while (1) 
    {
		UART0_transmit('K');
		_delay_ms(1000);
		UART0_transmit('a');
		_delay_ms(1000);
		UART0_transmit('n');
		_delay_ms(1000);
		UART0_transmit('g');
		_delay_ms(1000);
		UART0_transmit('H');
		_delay_ms(1000);
		UART0_transmit('y');
		_delay_ms(1000);
		UART0_transmit('e');
		_delay_ms(1000);
		UART0_transmit('o');
		_delay_ms(1000);
		UART0_transmit('n');
		_delay_ms(1000);
		UART0_transmit('G');
		_delay_ms(1000);
		UART0_transmit('u');
		_delay_ms(1000);
		UART0_transmit('\n');
		_delay_ms(1000);
    }
}

