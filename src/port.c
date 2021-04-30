#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
#include<avr/interrupt.h>

 void port()
 {
    DDRB |= (1<<PB0); //setting D port as output for led
    DDRD &=~(1<<PD2); // setting input obtain from button in occupancy of seat 
    DDRD &=~(1<<PD3); // setting input of a button Heater switch

    PORTD|=(1<<PD2); //configure pin PD2 as an input- DDRD-'0' and PORTD-'1'
    PORTD|=(1<<PD3); //configure pin PD3 as an input- DDRD-'0' and PORTD-'1'

    EICRA|=(1<<ISC00)|(1<<ISC10); // interupt 
    EIMSK|=(1<<INT0)|(1<<INT1);   // mask for interrupt 
    sei(); 
 }




