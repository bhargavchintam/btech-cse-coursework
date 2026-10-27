// linear search - works on any array, sorted or not
#include<stdio.h>

int main() {
    int a[100], n, i, key, pos = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        printf("Element not found\n");
    else
        printf("Found at position %d\n", pos + 1);
    return 0;
}
