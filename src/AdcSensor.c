#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
void AdcSesnor()
    {
        ADMUX|=(1<<REFS0);
        ADCSRA|=(1<<ADEN)|(1<<ADPS0);
    }

