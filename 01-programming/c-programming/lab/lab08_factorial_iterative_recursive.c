/* Lab Program 8
   Find the factorial of a number, iterative and recursive versions.
   gcc lab08_factorial_iterative_recursive.c -o lab08  */

#include<stdio.h>

long int fact_rec(int n)
{
    if(n == 0)
        return 1;
    return n * fact_rec(n - 1);
}

int main()
{
    int n, i;
    long int fact = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        fact = fact * i;

    printf("Factorial (iterative) = %ld\n", fact);
    printf("Factorial (recursive) = %ld\n", fact_rec(n));
    return 0;
}
