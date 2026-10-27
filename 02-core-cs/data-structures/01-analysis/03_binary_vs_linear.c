// binary O(log n) vs linear O(n) - compare the counts
#include<stdio.h>

#define MAX 10000

int lin(int a[], int n, int key)
{
    int i, c = 0;
    for (i = 0; i < n; i++) {
        c++;
        if (a[i] == key)
            break;
    }
    return c;
}

int bin(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid, c = 0;
    while (low <= high) {
        c++;
        mid = (low + high) / 2;
        if (a[mid] == key)
            return c;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return c;
}

int main()
{
    int n, i, key;
    int a[MAX];

    printf("   n    linear    binary\n");
    for (n = 1000; n <= MAX; n += 1000) {
        for (i = 0; i < n; i++)
            a[i] = i + 1;              // sorted 1..n

        key = 0;                       // absent -> worst case for both
        printf("%6d   %6d    %6d\n", n, lin(a, n, key), bin(a, n, key));
    }
    return 0;
}
