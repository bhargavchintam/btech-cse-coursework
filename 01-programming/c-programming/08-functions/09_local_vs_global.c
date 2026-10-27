#include<stdio.h>

int x = 100;

void show()
{
    int x = 50;
    printf("Local x = %d\n", x);
}

int main()
{
    show();
    printf("Global x = %d\n", x);
    return 0;
}
