#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
void AdcSesnor()
    {
        ADMUX|=(1<<REFS0);
        ADCSRA|=(1<<ADEN)|(1<<ADPS0);
    }
uint16_t ReadAdc(uint8_t ch)
    {
        ADMUX&=0xf8;
        ch&=0x7;
        ADMUX|=ch;
        ADCSRA|=(1<<ADSC);
        while(!(ADCSRA&(1<<ADIF)));
        ADCSRA|=(1<<ADIF);
        return(ADC);
    }

