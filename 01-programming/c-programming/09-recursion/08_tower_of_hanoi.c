// tower of hanoi
#include<stdio.h>

void hanoi(int n, char from, char to, char via)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, via, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, via, to, from);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
