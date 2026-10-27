// decimal to binary
#include<stdio.h>

int main()
{
    int n, i, bin[32], c = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if(n == 0)
        bin[c++] = 0;
    while(n > 0)
    {
        bin[c++] = n % 2;
        n = n / 2;
    }
    printf("Binary = ");
    for(i = c - 1; i >= 0; i--)
        printf("%d", bin[i]);
    printf("\n");
    return 0;
}
