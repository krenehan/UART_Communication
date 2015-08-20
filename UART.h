/*
 * UART.h
 *
 * Created: 8/19/2015 10:10:38 PM
 *  Author: Kevin Renehan
 */ 


#ifndef UART_H_
#define UART_H_


void UART_init(unsigned int ubrr);
void USART_Transmit( unsigned char data);
unsigned char USART_Receive( void );
void printString(unsigned char myString[]);



#endif /* UART_H_ */