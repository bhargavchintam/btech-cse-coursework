#include<stdio.h>

int main()
{
    int n, i = 0, arr[32];
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    while(n > 0)
    {
        arr[i] = n % 2;
        //printf("%d\n", arr[i]);
        n = n / 2;
        i++;
    }
    printf("Binary = ");
    for(i = i - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
