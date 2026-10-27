#include<stdio.h>

// nth term of fibonacci series
int main()
{
    int n, i = 1, a = 0, b = 1, c;
    printf("Enter the position n: ");
    scanf("%d", &n);
    while(i < n)
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    printf("Term %d = %d\n", n, a);
    return 0;
}
