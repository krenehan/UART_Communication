/*
 * UART_Communication.c
 *
 * Created: 8/8/2015 10:33:17 PM
 *  Author: Kevin Renehan
 */ 


#include <avr/io.h>
#include "UART_Communication.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART.h"


int main(void)
{
	char serialCharacter;
	UART_init(MYUBRR);
	/*unsigned char x[] = "Hello World!/r/n";
	printString(x);*/
	
	//Power Reduction Register
	PRR |= (1<<PRTIM0) | (1<<PRTIM1) | (1<<PRTIM2) | (1<<PRTWI) | (1<<PRADC);
	
    while(1)
    {
        //TODO:: Please write your application code 
		serialCharacter = USART_Receive();
		USART_Transmit(serialCharacter);
    }
}