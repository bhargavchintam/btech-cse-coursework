// gcc 03_roots_quadratic_math.c -o roots -lm
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, d, r1, r2;
    printf("Enter a, b, c : ");
    scanf("%f %f %f", &a, &b, &c);

    d = b*b - 4*a*c;
    if(d > 0)
    {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("Roots are %.3f and %.3f\n", r1, r2);
    }
    else if(d == 0)
    {
        r1 = -b / (2*a);
        printf("Roots are real and equal : %.3f\n", r1);
    }
    else
    {
        float real = -b / (2*a);
        float imag = sqrt(-d) / (2*a);
        printf("Roots are complex : %.3f+%.3fi and %.3f-%.3fi\n", real, imag, real, imag);
    }
    return 0;
}
