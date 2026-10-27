#include<stdio.h>

int main()
{
    char str[] = "hello world";
    char *p;
    p = str;
    while(*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
    return 0;
}
