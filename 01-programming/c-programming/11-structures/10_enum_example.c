// enum for days of week
#include<stdio.h>

enum day {MON, TUE, WED, THU, FRI, SAT, SUN};

int main()
{
    enum day d;
    int i;

    d = WED;
    printf("Value of WED = %d\n", d);

    printf("All days : ");
    for(i = MON; i <= SUN; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}
