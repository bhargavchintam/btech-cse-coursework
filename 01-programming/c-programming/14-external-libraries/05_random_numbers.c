// gcc 05_random_numbers.c -o random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, n;
    printf("How many random numbers? ");
    scanf("%d", &n);

    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        printf("%d\n", rand() % 100);
    }
    return 0;
}
