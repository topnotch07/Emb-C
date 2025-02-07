#include"Registors.h"
#include<avr/io.h>

  void Registors(void)
  {
        DDRD|=(1<<PB1); // setting B1 port as pwm output for timer1

        TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10); //Enabling Fast PWM timer-16bit  (non-inverting mode) in channel A
        TCCR1B |= (1<<WGM12)| (1<<CS12);  // setting prescalar value of 256
    
   /**TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);  //Enabling Fast PWM timer-8bit (non-inverting mode) in channel A
    
    TCCR0B|=(1<<CS00)|(1<<CS02); // setting prescalar value of 1024*/ 
    
  }

char out_PWM(uint16_t val)
{
  char count=0;

    if((val>=0) && (val<=209))
    {

        OCR1A = 205;//20% duty cycle
        count=20;
    }
    else if((val>=210) && (val<=509))
    {

        OCR1A = 410; //40% duty cycle
        count=25;
    }
    else if((val>=510) && (val<=709))
    {

        OCR1A = 717;//70% duty cycle
        count=29;
    }
    else if((val>=710) && (val<=1024))
    {

        OCR1A = 973; //95% duty cycle
        count=33;
    }
    else
    {
        OCR1A = 0; //0% output
        count=0;
    }
    return count;
}

