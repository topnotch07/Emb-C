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
#include<avr/io.h>
#include <stdint.h>
/**
 * @brief function to initialise UART registers in asynchronous mode
 * 
 */

void UART_init(uint16_t value);            
/**
 * @brief function to transmit the data and write data to UART buffer
 * 
 * @param data 
 */
void UART_WRITE(char data);  

#endif // UART_H_INCLUDED
