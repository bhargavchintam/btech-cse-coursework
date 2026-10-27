#include<stdio.h>
int main()
{
    int ch;
    float s, l, b, h, area;
    printf("1. Area of square\n");
    printf("2. Area of rectangle\n");
    printf("3. Area of triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            printf("Enter side: ");
            scanf("%f", &s);
            area = s * s;
            printf("Area = %f\n", area);
            break;
        case 2:
            printf("Enter length and breadth: ");
            scanf("%f %f", &l, &b);
            area = l * b;
            printf("Area = %f\n", area);
            break;
        case 3:
            printf("Enter base and height: ");
            scanf("%f %f", &b, &h);
            area = 0.5 * b * h;
            printf("Area = %f\n", area);
            break;
        default:
            printf("Wrong choice\n");
    }
    return 0;
}
