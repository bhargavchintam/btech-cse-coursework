// kth largest element using a max heap
#include<stdio.h>
#define SIZE 100

int heap[SIZE];
int n;

void heapify(int i)
{
    int large = i, l = 2*i + 1, r = 2*i + 2, t;
    if(l < n && heap[l] > heap[large])
        large = l;
    if(r < n && heap[r] > heap[large])
        large = r;
    if(large != i)
    {
        t = heap[i];
        heap[i] = heap[large];
        heap[large] = t;
        heapify(large);
    }
}

int delete_max()
{
    int max = heap[0];
    n--;
    heap[0] = heap[n];
    heapify(0);
    return max;
}

int main()
{
    int i, k, size, kth = -1;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements\n", size);
    for(i = 0; i < size; i++)
        scanf("%d", &heap[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    n = size;
    for(i = n/2 - 1; i >= 0; i--)
        heapify(i);
    // pop the max k times, kth pop is the answer
    for(i = 0; i < k; i++)
        kth = delete_max();
    printf("%d largest element = %d\n", k, kth);
    return 0;
}
