/* Lab Program 11
   Sort n integers in ascending order using bubble sort, printing each pass.
   gcc lab11_bubble_sort.c -o lab11  */

#include<stdio.h>

int main() {
    int i, j, n, temp;
    int arr[50];

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d numbers\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d : ", i + 1);
        for(j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }

    printf("Sorted array : ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
