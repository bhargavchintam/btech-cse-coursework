#include<stdio.h>

// grows insanely fast, keep m small (0..3)
int ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

int main()
{
    int m, n;
    printf("Enter m and n (small values): ");
    scanf("%d %d", &m, &n);
    printf("Ackermann(%d,%d) = %d\n", m, n, ack(m, n));
    return 0;
}
