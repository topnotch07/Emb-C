#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
#include<avr/interrupt.h>


unsigned volatile flag=0,flag1=0;

ISR(INT0_vect)
{
    flag=1;
}
ISR(INT1_vect)
{
    flag1=1;
}

void Led_On()
{

    PORTB|=(1<<PB0);
}

void LedOff()
{
   PORTB&=~(1<<PB0);
}

