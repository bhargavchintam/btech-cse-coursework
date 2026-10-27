// merge k sorted arrays using a min heap
#include<stdio.h>
#define K 20
#define SIZE 100

int arr[K][SIZE];
int len[K];

struct node
{
    int val;
    int a;      // which array it came from
    int i;      // its index in that array
};

struct node heap[K];
int hs = 0;     // heap size

void push(struct node x)
{
    int c, p;
    struct node t;
    heap[hs] = x;
    c = hs;
    hs++;
    while(c > 0)
    {
        p = (c - 1) / 2;
        if(heap[p].val <= heap[c].val)
            break;
        t = heap[p];
        heap[p] = heap[c];
        heap[c] = t;
        c = p;
    }
}

struct node pop()
{
    struct node min = heap[0], t;
    int i, child;
    hs--;
    heap[0] = heap[hs];
    i = 0;
    while(2*i + 1 < hs)
    {
        child = 2*i + 1;
        if(child + 1 < hs && heap[child+1].val < heap[child].val)
            child++;
        if(heap[i].val <= heap[child].val)
            break;
        t = heap[i];
        heap[i] = heap[child];
        heap[child] = t;
        i = child;
    }
    return min;
}

int main()
{
    int k, i, j;
    struct node x, min;
    printf("Enter number of arrays: ");
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &len[i]);
        printf("Enter %d sorted elements\n", len[i]);
        for(j = 0; j < len[i]; j++)
            scanf("%d", &arr[i][j]);
    }
    // seed the heap with the first element of each array
    for(i = 0; i < k; i++)
    {
        if(len[i] > 0)
        {
            x.val = arr[i][0];
            x.a = i;
            x.i = 0;
            push(x);
        }
    }
    printf("Merged : ");
    while(hs > 0)
    {
        min = pop();
        printf("%d ", min.val);
        if(min.i + 1 < len[min.a])
        {
            x.val = arr[min.a][min.i + 1];
            x.a = min.a;
            x.i = min.i + 1;
            push(x);
        }
    }
    printf("\n");
    return 0;
}
