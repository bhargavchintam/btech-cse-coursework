/* min heap - insert, delete min, display */
#include<stdio.h>
#define SIZE 100

int heap[SIZE];
int n = 0;

void insert(int val) {
    int i, t;
    if(n == SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    heap[++n] = val;
    i = n;
    while(i > 1 && heap[i/2] > heap[i]) {
        t = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = t;
        i = i / 2;
    }
}

int delete_min() {
    int min, i, child, t;
    if(n == 0) {
        printf("Underflow\n");
        return -1;
    }
    min = heap[1];
    heap[1] = heap[n];
    n--;
    i = 1;
    while(2*i <= n) {
        child = 2 * i;
        if(child < n && heap[child+1] < heap[child])
            child++;
        if(heap[i] <= heap[child])
            break;
        t = heap[i];
        heap[i] = heap[child];
        heap[child] = t;
        i = child;
    }
    return min;
}

void display() {
    int i;
    if(n == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap : ");
    for(i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int ch, val, min;
    while(1) {
        printf("\n1.Insert  2.Delete-min  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                min = delete_min();
                if(min != -1)
                    printf("Deleted min = %d\n", min);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
