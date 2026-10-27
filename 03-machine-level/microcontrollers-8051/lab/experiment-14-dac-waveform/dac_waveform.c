// generate a ramp and a triangular wave on an R-2R DAC wired to port 1
// 00H -> 0V, FFH -> full scale
#include <8051.h>

void ramp(void)
{
    unsigned int v;               // int so the value 256 ends the loop
    for (v = 0; v <= 0xFF; v++)
        P1 = (unsigned char)v;    // rising slope, snaps back at wrap
}

void triangle(void)
{
    unsigned int v;
    for (v = 0; v <= 0xFF; v++)   // rising half
        P1 = (unsigned char)v;
    for (v = 0xFF; v > 0; v--)    // falling half
        P1 = (unsigned char)v;
}

void main(void)
{
    while (1) {
        ramp();
        triangle();
    }
}
