// counting sort - non negative integers, no comparisons
#include<stdio.h>
#define RANGE 1000

int main() {
    int a[100], count[RANGE] = {0}, n, i, k, max;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements (>= 0)\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];

    for(i = 0; i < n; i++)
        count[a[i]]++;

    k = 0;
    for(i = 0; i <= max; i++)
        while(count[i]-- > 0)
            a[k++] = i;

    printf("Sorted array\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
