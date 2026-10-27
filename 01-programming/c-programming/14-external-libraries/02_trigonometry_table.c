// gcc 02_trigonometry_table.c -o trig -lm
#include<stdio.h>
#include<math.h>

int main()
{
    int deg;
    double rad;

    printf("Deg\tsin\tcos\ttan\n");
    for(deg = 0; deg <= 90; deg += 15)
    {
        rad = deg * M_PI / 180.0;
        printf("%d\t%.3lf\t%.3lf\t%.3lf\n", deg, sin(rad), cos(rad), tan(rad));
    }
    return 0;
}
