// blink the eight LEDs on port 1 with a software delay
#include <8051.h>

void delay(unsigned int count)
{
    unsigned int i;
    while (count--)
        for (i = 0; i < 121; i++);   // burn a few thousand cycles
}

void main(void)
{
    while (1) {
        P1 = 0x00;   // active-low LEDs on (port sinks current)
        delay(250);
        P1 = 0xFF;   // all LEDs off
        delay(250);
    }
}
