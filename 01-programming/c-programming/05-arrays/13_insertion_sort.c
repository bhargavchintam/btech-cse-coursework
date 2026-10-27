/* Bindu Bhargava
   28-11-17 */
// insertion sort
#include<stdio.h>
int main() {
    int a[50], n, i, j, key;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=1;i<n;i++) {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    printf("Sorted array\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
