#include<stdio.h>

void printArray(int arr[], int i, int n)
{
    if(i == n)
        return;
    printf("%d ", arr[i]);
    printArray(arr, i + 1, n);
}

int main()
{
    int arr[50], n, i;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printArray(arr, 0, n);
    printf("\n");
    return 0;
}
