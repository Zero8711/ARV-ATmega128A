/*
 * UART2.c
 *
 * Created: 2022-07-27 오후 12:22:11
 * Author : KCCI17
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
		char data = UART0_receive();
		UART0_transmit(data);
		_delay_ms(10);
	}
}

