// reverse a queue using a stack
#include<stdio.h>
#define SIZE 100

int queue[SIZE], stack[SIZE];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main() {
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Original queue : ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    while (front <= rear)
        push(dequeue());

    front = 0;
    rear = -1;
    while (top != -1)
        enqueue(pop());

    printf("Reversed queue : ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}
