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


int main()
{
  port();
  AdcSesnor();
  uint16_t temp=0;
  unsigned int duty=0; 
  Registors();
  UART_init();
  
  while(1)
  {
    if(flag==1)
        {
            if(flag1==1)
            {
              Led_On();
              temp=ReadAdc(1);
              out_PWM(temp);
              UART_READ(temp);
              UART_WRITE(temp);
              for(duty=0;duty<1024;duty++)
              {
                OCR1A=duty;
              }
              flag1=0;
            }
            else
            {
                LedOff();
            }
            flag=0;
        }
  }
  return 0;
}

 
