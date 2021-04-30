#include"port.h"
#include<avr/io.h>

/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */

void ledstatus(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}
void InitializeLED(void)
{
	DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    PORTD|=(1<<PD1);
}




