// build a max heap from an arbitrary array (bottom up)
#include<stdio.h>
#define SIZE 100

int a[SIZE], n;

void sift_down(int i)
{
    int large = i, l = 2*i + 1, r = 2*i + 2, t;
    if(l < n && a[l] > a[large])
        large = l;
    if(r < n && a[r] > a[large])
        large = r;
    if(large != i)
    {
        t = a[i];
        a[i] = a[large];
        a[large] = t;
        sift_down(large);
    }
}

int main()
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // last internal node is at n/2 - 1, work upward to the root
    for(i = n/2 - 1; i >= 0; i--)
        sift_down(i);
    printf("Max heap array : ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
