#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

 void port(void)
 {
    DDRB |= (1<<PB0); //setting D port as output for led
    DDRD &=~(1<<PD0); // setting input obtain from button in occupancy of seat 
    DDRD &=~(1<<PD1); // setting input of a button Heater switch

    PORTD|=(1<<PD0); //configure pin PD2 as an input- DDRD-'0' and PORTD-'1'
    PORTD|=(1<<PD1); //configure pin PD3 as an input- DDRD-'0' and PORTD-'1'
 }




