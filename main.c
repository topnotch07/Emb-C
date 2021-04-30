#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

int main()
{
  port();
  AdcSesnor();
  uint16_t temp=0;
  Registors();
  UART_init();
  char data=0;
  sei();
  while(1)
  (
    if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1))
        {
          Led_On();
          temp=ReadAdc(1);
          data=out_PWM(temp);
          UART_WRITE(data);
         }
        else
        {
          LedOff();
          OCR1A=0;
        }
  }
  return 0;
}

 
