#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
#include<avr/io.h>

void Led_On(void)
{

    PORTB|=(1<<PB0); //Led On at mentioned Pin(PB0)
}

void LedOff(void)
{
   PORTB&=~(1<<PB0); // Led turn OFF 
}

