// priority queue using a max heap (higher number = higher priority)
#include<stdio.h>
#define SIZE 100

struct item
{
    int data;
    int prio;
};

struct item heap[SIZE];
int n = 0;

void enqueue(int data, int prio)
{
    int i;
    struct item t;
    n++;
    heap[n].data = data;
    heap[n].prio = prio;
    i = n;
    while(i > 1 && heap[i/2].prio < heap[i].prio)
    {
        t = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = t;
        i = i / 2;
    }
}

int dequeue()
{
    int i, child;
    struct item t, top;
    if(n == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    top = heap[1];
    heap[1] = heap[n];
    n--;
    i = 1;
    while(2*i <= n)
    {
        child = 2 * i;
        if(child < n && heap[child+1].prio > heap[child].prio)
            child++;
        if(heap[i].prio >= heap[child].prio)
            break;
        t = heap[i];
        heap[i] = heap[child];
        heap[child] = t;
        i = child;
    }
    return top.data;
}

void display()
{
    int i;
    printf("(data,priority): ");
    for(i = 1; i <= n; i++)
        printf("(%d,%d) ", heap[i].data, heap[i].prio);
    printf("\n");
}

int main()
{
    int ch, data, prio, d;
    while(1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &prio);
                enqueue(data, prio);
                break;
            case 2:
                d = dequeue();
                if(d != -1)
                    printf("Served (highest priority) = %d\n", d);
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
