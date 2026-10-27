// gcc 01_math_functions.c -o math -lm
#include<stdio.h>
#include<math.h>

int main()
{
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);

    printf("sqrt(%.2lf) = %.4lf\n", x, sqrt(x));
    printf("pow(%.2lf, %.2lf) = %.4lf\n", x, y, pow(x, y));
    printf("floor(%.2lf) = %.4lf\n", x, floor(x));
    printf("ceil(%.2lf) = %.4lf\n", x, ceil(x));
    printf("fabs(%.2lf) = %.4lf\n", x, fabs(x));
    printf("log(%.2lf) = %.4lf\n", x, log(x));
    printf("exp(%.2lf) = %.4lf\n", x, exp(x));

    return 0;
}
