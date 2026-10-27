// area of circle rectangle and triangle
#include<stdio.h>

float circle(float r)
{
    return 3.14 * r * r;
}

float rectangle(float l, float b)
{
    return l * b;
}

float triangle(float base, float h)
{
    return 0.5 * base * h;
}

int main()
{
    float r, l, b, base, h;
    printf("Enter radius : ");
    scanf("%f", &r);
    printf("Circle area = %f\n", circle(r));
    printf("Enter length and breadth : ");
    scanf("%f %f", &l, &b);
    printf("Rectangle area = %f\n", rectangle(l, b));
    printf("Enter base and height : ");
    scanf("%f %f", &base, &h);
    printf("Triangle area = %f\n", triangle(base, h));
    return 0;
}
