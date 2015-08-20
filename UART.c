/*
 * UART.c
 *
 * Created: 8/19/2015 10:07:15 PM
 *  Author: Kevin Renehan
 */ 

#include <avr/io.h>
#include "UART_Communication.h"
#include "UART.h"

void UART_init(unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}

void printString(unsigned char myString[])
{
	uint8_t i = 0;
	while (myString[i])
	{
		USART_Transmit(myString[i]);
		i++;
	}
}
