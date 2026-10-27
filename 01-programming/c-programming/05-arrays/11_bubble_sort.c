// bubble sort in ascending order
#include<stdio.h>
int main() {
    int a[50], n, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted array\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
