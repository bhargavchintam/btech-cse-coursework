/* Lab Program 1
   Read principal, time and rate and compute the simple interest.
   gcc lab01_simple_interest.c -o lab01  */

#include<stdio.h>

int main() {
    float p, t, r, si;
    printf("Enter principal, time and rate : ");
    scanf("%f %f %f", &p, &t, &r);
    si = (p * t * r) / 100;
    printf("Simple Interest = %f\n", si);
    return 0;
}
