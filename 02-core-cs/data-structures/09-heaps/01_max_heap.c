// max heap using array - insert, delete max, display
#include<stdio.h>
#define SIZE 100

int heap[SIZE];
int n = 0;      // number of elements, stored in heap[1..n]

void insert(int val)
{
    int i, t;
    if(n == SIZE - 1)
    {
        printf("Heap is full\n");
        return;
    }
    n++;
    heap[n] = val;
    i = n;
    while(i > 1 && heap[i/2] < heap[i])
    {
        t = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = t;
        //printf("swapped up, i=%d\n", i);
        i = i / 2;
    }
    printf("%d inserted\n", val);
}

int delete_max()
{
    int max, i, child, t;
    if(n == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }
    max = heap[1];
    heap[1] = heap[n];
    n--;
    i = 1;
    while(2*i <= n)
    {
        child = 2 * i;
        if(child < n && heap[child+1] > heap[child])
            child++;
        if(heap[i] >= heap[child])
            break;
        t = heap[i];
        heap[i] = heap[child];
        heap[child] = t;
        i = child;
    }
    return max;
}

void display()
{
    int i;
    if(n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap : ");
    for(i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main()
{
    int ch, val, max;
    while(1)
    {
        printf("\n1.Insert  2.Delete-max  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                max = delete_max();
                if(max != -1)
                    printf("Deleted max = %d\n", max);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
