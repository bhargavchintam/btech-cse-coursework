#include<stdio.h>

int main()
{
    int i, stop;
    printf("Enter the stop value: ");
    scanf("%d", &stop);
    for(i = 1; i <= 100; i++)
    {
        if(i == stop)
            break;
        if(i % 3 == 0)
            continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
