// full-step drive for a unipolar stepper on P1.0-P1.3
// two coils energised each step; reverse the order to change direction
#include <8051.h>

__code const unsigned char step[4] = { 0x09, 0x0C, 0x06, 0x03 };

void delay(unsigned int n)
{
    unsigned int i;
    while (n--)
        for (i = 0; i < 120; i++);
}

void forward(void)
{
    unsigned char i;
    for (i = 0; i < 4; i++) {
        P1 = step[i];
        delay(30);
    }
}

void reverse(void)
{
    unsigned char i;
    for (i = 4; i > 0; i--) {
        P1 = step[i - 1];
        delay(30);
    }
}

void main(void)
{
    unsigned char n;
    while (1) {
        for (n = 0; n < 50; n++)   // 50 cycles one way
            forward();
        for (n = 0; n < 50; n++)   // then 50 back
            reverse();
    }
}
