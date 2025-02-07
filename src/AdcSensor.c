#include"AdcSensor.h"
#include<avr/io.h>

void AdcSesnor(void)
    {
        ADMUX|=(1<<REFS0);    //ADMUX register and 0 Aref connected to AVCC internally in MCU
        ADCSRA|=(1<<ADEN)|(7<<ADPS0);    // Enabling ADC and setting the sampling frequency through ADCSRA registor
    }

uint16_t  ReadAdc(uint8_t ch)
    {
        ADMUX&=0xf8;  // Selecting channel 0 by setting 1 to all ADMUX register except Bit 0,1,2
        ch&=0x7;      // logical AND with 0x7 (binary representation: 0b00000111) will give the channel itsef
        ADMUX|=ch;   // selecting the channel by OR with ADMUX.
        ADCSRA|=(1<<ADSC);      // Start single conversion by enabling Bit 6 in ADCSRA registor

        while(!(ADCSRA&(1<<ADIF)));      // conversion

        ADCSRA|=(1<<ADIF);
        return(ADC);
    }

