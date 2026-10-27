// generate a ramp and a triangle wave on an R-2R DAC wired to port 1
// 00H -> 0V, FFH -> full scale
#include <8051.h>

void ramp(void)
{
    unsigned int v;               // int so 256 terminates the loop
    for (v = 0; v <= 0xFF; v++)
        P1 = (unsigned char)v;    // rising edge, snaps back at wrap
}

void triangle(void)
{
    unsigned int v;
    for (v = 0; v <= 0xFF; v++)   // rise
        P1 = (unsigned char)v;
    for (v = 0xFF; v > 0; v--)    // fall
        P1 = (unsigned char)v;
}

void main(void)
{
    while (1) {
        ramp();
        triangle();
    }
}
