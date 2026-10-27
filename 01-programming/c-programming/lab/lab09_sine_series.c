/* Lab Program 9
   Compute sin(x) using its Taylor series and compare with the library sin().
   gcc lab09_sine_series.c -o lab09 -lm  */

#include<stdio.h>
#include<math.h>

int main()
{
    int i, n;
    double x, rad, term, sum;

    printf("Enter the value of x in degrees : ");
    scanf("%lf", &x);
    printf("Enter the number of terms : ");
    scanf("%d", &n);

    rad = x * 3.141592653589793 / 180.0;
    term = rad;
    sum = 0.0;
    for(i = 1; i <= n; i++)
    {
        sum = sum + term;
        term = -term * rad * rad / ((2 * i) * (2 * i + 1));
    }

    printf("sin(%f) by series  = %lf\n", x, sum);
    printf("sin(%f) by library = %lf\n", x, sin(rad));
    return 0;
}
