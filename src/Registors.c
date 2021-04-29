#include"AdcSensor.h"
#include"Uart.h"
#include"Registors.h"
#include"port.h"

  void Registors()
  {
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B|=(1<<CS00)|(1<<CS02);
    DDRD|=(1<<PD6);
  }
