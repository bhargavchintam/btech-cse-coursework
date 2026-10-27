// sentinel linear search - put key at the end so the loop always stops
#include<stdio.h>

int main() {
    int a[101], n, i, key;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    a[n] = key;             // sentinel
    i = 0;
    while(a[i] != key)
        i++;

    if(i < n)
        printf("Found at position %d\n", i + 1);
    else
        printf("Element not found\n");
    return 0;
}
