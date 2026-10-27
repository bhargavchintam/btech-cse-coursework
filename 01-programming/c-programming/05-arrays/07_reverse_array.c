// reverse an array
#include<stdio.h>
int main() {
    int a[50], n, i, temp;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n/2;i++) {
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    printf("Reversed array\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
