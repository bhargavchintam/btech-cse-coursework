#include<stdio.h>

int binsearch(int a[], int low, int high, int key) {
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binsearch(a, low, mid - 1, key);
    else
        return binsearch(a, mid + 1, high, key);
}

int main() {
    int a[100], n, i, key, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binsearch(a, 0, n - 1, key);
    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos + 1);
    return 0;
}
