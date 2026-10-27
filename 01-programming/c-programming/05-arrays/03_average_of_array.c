// average of array elements
#include<stdio.h>
int main() {
    int a[50], n, i, sum=0;
    float avg;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
        sum += a[i];
    avg = (float)sum / n;
    printf("Average = %.2f\n", avg);
    return 0;
}
