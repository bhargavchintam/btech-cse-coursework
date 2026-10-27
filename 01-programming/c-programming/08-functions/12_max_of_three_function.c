// max of three numbers using function
#include<stdio.h>

int max(int a, int b, int c)
{
    int m = a;
    if(b > m)
        m = b;
    if(c > m)
        m = c;
    return m;
}

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Maximum = %d\n", max(a, b, c));
    return 0;
}
