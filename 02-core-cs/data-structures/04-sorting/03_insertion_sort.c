// insertion sort - insert each element into the sorted left part
#include<stdio.h>

int main() {
    int a[100], n, i, j, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {   // shift right
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    printf("Sorted array\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
