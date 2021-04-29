#include <avr/io.h>
#include<avr/interrupt.h>

 void port()
 {

    DDRB |= (1<<PB0);
    DDRD &=~(1<<PD2);
    DDRD &=~(1<<PD3);

    PORTD|=(1<<PD2);
    PORTD|=(1<<PD3);

    EICRA|=(1<<ISC00)|(1<<ISC10);
    EIMSK|=(1<<INT0)|(1<<INT1);
    sei();
 }




