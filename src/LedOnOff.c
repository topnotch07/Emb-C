#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

void Led_On()
{

    PORTB|=(1<<PB0);
}

void LedOff()
{
   PORTB&=~(1<<PB0);
}

