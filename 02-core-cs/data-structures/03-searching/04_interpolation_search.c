// interpolation search - sorted + roughly uniform data
#include<stdio.h>

int main()
{
    int a[100], n, i, key, low, high, probe, pos = -1;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    while (low <= high && key >= a[low] && key <= a[high])
    {
        if (a[high] == a[low])
        {
            if (a[low] == key)
                pos = low;
            break;
        }
        probe = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);
        if (a[probe] == key)
        {
            pos = probe;
            break;
        }
        else if (a[probe] < key)
            low = probe + 1;
        else
            high = probe - 1;
    }

    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Found at position %d\n", pos + 1);
    return 0;
}
