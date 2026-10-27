// blink all eight LEDs on port 1 with a software delay
#include <8051.h>

void delay(unsigned int n)
{
    unsigned int i;
    while (n--)
        for (i = 0; i < 120; i++);   // burn a few thousand cycles
}

void main(void)
{
    while (1) {
        P1 = 0x00;   // active-low LEDs on (port sinks)
        delay(250);
        P1 = 0xFF;   // all off
        delay(250);
    }
}
