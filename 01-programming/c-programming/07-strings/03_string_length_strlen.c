#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int len;

    printf("enter a string : ");
    scanf("%s", str);

    len = strlen(str);
    printf("length = %d\n", len);

    return 0;
}
