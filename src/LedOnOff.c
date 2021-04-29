#include <avr/io.h>
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
int LedOnAndOff()
{
     while(1)
    {
        if(flag==1)
        {
            if(flag1==1)
            {
                Led_On();
                flag1=0;
            }
            else
            {
                LedOff();
            }
            flag=0;
        }
    }
 }
