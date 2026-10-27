/* Lab Program 3
   Compute the roots of a quadratic equation. Handle all three cases of the
   discriminant.
   gcc lab03_quadratic_roots.c -o lab03 -lm  */

#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, d, r1, r2, real, imag;
    printf("Enter coefficients a, b and c : ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if(d > 0)
    {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are real and distinct\n");
        printf("r1 = %f r2 = %f\n", r1, r2);
    }
    else if(d == 0)
    {
        r1 = -b / (2 * a);
        printf("Roots are real and equal\n");
        printf("r1 = r2 = %f\n", r1);
    }
    else
    {
        real = -b / (2 * a);
        imag = sqrt(-d) / (2 * a);
        printf("Roots are complex\n");
        printf("r1 = %f + %fi\n", real, imag);
        printf("r2 = %f - %fi\n", real, imag);
    }
    return 0;
}
