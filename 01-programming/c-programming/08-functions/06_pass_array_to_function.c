/* Bindu Bhargava
   19-11-17 */
#include<stdio.h>

int sumArray(int arr[], int n)
{
    int i, sum = 0;
    for(i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int arr[50], n, i;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Sum = %d\n", sumArray(arr, n));
    return 0;
}
