/**
 * @file uart.h
 * @author Thiruvikraman B
 * @brief Include header file for activity 4
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED
#define BAUD 9600
#define F_CPU 16000000UL
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)
void UART_init();
char UART_READ();
void UART_WRITE(char data);
#endif // UART_H_INCLUDED
