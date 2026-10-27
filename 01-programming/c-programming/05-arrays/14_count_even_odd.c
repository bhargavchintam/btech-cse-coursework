// count even and odd numbers in an array
#include<stdio.h>
int main()
{
    int a[50], n, i, even=0, odd=0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2 == 0)
            even++;
        else
            odd++;
    }
    printf("Even count = %d\n", even);
    printf("Odd count = %d\n", odd);
    return 0;
}
