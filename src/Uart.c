#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

uint16_t value=BAUD_RATE;
void UART_init()
{

    UBRR0H=(value>>8)&0x0ff;     //setting Baud rate
    UBRR0L=value;
    UCSR0C|=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    UCSR0B|=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0); //enable Transmitter and Reciever
}
char UART_READ()
{
    while(!(UCSR0A & (1<<RXC0))) //unread data in reciever-USART Receive Complete
        ; //do nothing
    return UDR0;
}
void UART_WRITE(char data)
{
    while(!(UCSR0A & (1<<UDRE0))) // Ready to recieve new data-USART Data Register Empty
        ; //do nothing
    UDR0=data;

}
