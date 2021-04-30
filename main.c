#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
#include<avr/io.h>
#include <stdint.h>

uint16_t temp=0;
char data=0;

int main()
{
  InitializeLED();
  AdcSesnor();
  Registors();
  UART_init(103);
 
  while(1)
  {
   if(SEATSENSOR_ON ) //If switch_1 is ON
        {
          if(HEATSENSOR_ON) //If switch_2 is ON
            {
                ledstatus(LED_ON);//LED is ON
                temp=ReadAdc(1);
                data=out_PWM(temp);
                UART_WRITE(data);
            }
            else
            {
              ledstatus(LED_OFF);
            }
        }
        else
        {
          ledstatus(LED_OFF);//LED is OFF
          OCR1A=0;
        }

  }
  return 0;
}

 
