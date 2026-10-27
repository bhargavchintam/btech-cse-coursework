/* Lab Program 2
   Swap two numbers, with and without using a temporary variable.
   gcc lab02_swap_two_numbers.c -o lab02  */

#include<stdio.h>

int main()
{
    int a, b, temp;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;
    printf("After swapping using temp : a = %d b = %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping without temp : a = %d b = %d\n", a, b);
    return 0;
}
