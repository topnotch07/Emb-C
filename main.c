#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"
#include<avr/io.h>
 
uint16_t temp=0;
char data=0;

int main()
{
  InitLED();
  AdcSesnor();
  Registors();
  UART_init(103);
 
  while(1)
  {
   if(SENSOR_ON) //If switch_1 is ON
        {
          if(HEAT_ON) //If switch_2 is ON
            {
                ledstat(LED_ON);//LED is ON
                temp=ReadAdc(1);
                data=out_PWM(temp);
                UART_WRITE(data);
            }
            else
            {
              ledstat(LED_OFF);
            }
        }
        else
        {
          ledstat(LED_OFF);//LED is OFF
          OCR1A=0;
        }

  }
  return 0;
}

 
