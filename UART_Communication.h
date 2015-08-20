/*
 * UART_Communication.h
 *
 * Created: 8/19/2015 10:05:46 PM
 *  Author: Kevin Renehan
 */ 


#ifndef UART_COMMUNICATION_H_
#define UART_COMMUNICATION_H_

#define F_CPU 16000000
#define FOSC 16000000
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1

#endif /* UART_COMMUNICATION_H_ */