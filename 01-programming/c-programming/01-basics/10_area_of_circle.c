#include<stdio.h>
#define PI 3.14159
int main()
{
    float r, area;
    printf("Enter radius: ");
    scanf("%f", &r);
    area = PI * r * r;
    printf("Area = %f\n", area);
    return 0;
}
