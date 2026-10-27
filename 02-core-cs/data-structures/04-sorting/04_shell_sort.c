/* Bindu Bhargava   26-09-18 */
// shell sort - insertion sort but comparing elements a gap apart
#include<stdio.h>

int main()
{
    int a[100], n, i, j, gap, temp;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
