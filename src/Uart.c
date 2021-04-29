#include <avr/io.h>

#define BAUD 9600
#define F_CPU 16000000UL
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)
uint16_t value=BAUD_RATE;
void UART_init()
{

    UBRR0H=(value>>8)&0x0ff;
    UBRR0L=value;
    UCSR0C|=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    UCSR0B|=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}
char UART_READ()
{
    while(!(UCSR0A & (1<<RXC0)))
        ;
    return UDR0;
}
void UART_WRITE(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
        ;
    UDR0=data;

}
