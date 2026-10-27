// using a ROM (lookup table) to implement binary-to-gray for 3-bit inputs
#include<stdio.h>

int main()
{
    // rom[address] = stored gray code word
    int rom[8] = {0, 1, 3, 2, 6, 7, 5, 4};
    int i, b;
    printf("Addr(bin) | Data(gray)\n");
    for(i = 0; i < 8; i++)
    {
        for(b = 2; b >= 0; b--) printf("%d", (i >> b) & 1);
        printf("    |   ");
        for(b = 2; b >= 0; b--) printf("%d", (rom[i] >> b) & 1);
        printf("\n");
    }
    return 0;
}
