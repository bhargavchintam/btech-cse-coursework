/* Lab Program 7
   Print the first n terms of the Fibonacci series (iterative).
   gcc lab07_fibonacci_series.c -o lab07  */

#include<stdio.h>

int main() {
    int n, i, a = 0, b = 1, c;
    printf("Enter number of terms : ");
    scanf("%d", &n);

    printf("Fibonacci series : ");
    for(i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
