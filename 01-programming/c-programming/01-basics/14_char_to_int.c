#include<stdio.h>
int main()
{
    char ch;
    int n;
    printf("Enter a digit: ");
    scanf("%c", &ch);
    n = ch - '0';
    printf("Integer value = %d\n", n);
    return 0;
}
