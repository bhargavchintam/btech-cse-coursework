/* Bindu Bhargava   19-09-18 */
// first and last index of a key in a sorted array with duplicates
#include<stdio.h>

int firstocc(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid, res = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            res = mid;
            high = mid - 1;         // look further left
        }
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int lastocc(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid, res = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            res = mid;
            low = mid + 1;          // look further right
        }
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    int a[100], n, i, key, f, l;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    f = firstocc(a, n, key);
    l = lastocc(a, n, key);
    if (f == -1)
        printf("%d not present\n", key);
    else
        printf("First occurrence at index %d, last at index %d (count %d)\n", f, l, l - f + 1);
    return 0;
}
