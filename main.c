#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

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

 
