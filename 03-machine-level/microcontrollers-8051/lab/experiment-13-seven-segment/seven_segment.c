// count 0-9 on a common-cathode seven-segment wired to port 2
// bit0=a bit1=b bit2=c bit3=d bit4=e bit5=f bit6=g, segment on = 1
#include <8051.h>

// segment codes held in ROM
const __code unsigned char seg[10] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void delay(unsigned int count)
{
    unsigned int i;
    while (count--)
        for (i = 0; i < 120; i++);
}

void main(void)
{
    unsigned char d;
    while (1) {
        for (d = 0; d < 10; d++) {
            P2 = seg[d];     // show the digit
            delay(400);
        }
    }
}
