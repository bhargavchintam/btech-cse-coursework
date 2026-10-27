// implement a stack using two queues (push is made costly)
#include<stdio.h>
#define SIZE 20

struct queue
{
    int arr[SIZE];
    int front, rear, count;
};

struct queue q1, q2;

void init(struct queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueue(struct queue *q, int x)
{
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = x;
    q->count++;
}

int dequeue(struct queue *q)
{
    int x = q->arr[q->front];
    q->front = (q->front + 1) % SIZE;
    q->count--;
    return x;
}

int isempty(struct queue *q)
{
    return q->count == 0;
}

void push(int x)
{
    struct queue temp;
    enqueue(&q2, x);
    while(!isempty(&q1))
        enqueue(&q2, dequeue(&q1));
    temp = q1;
    q1 = q2;
    q2 = temp;
}

int pop()
{
    return dequeue(&q1);
}

void display()
{
    int i, idx;
    if(isempty(&q1))
    {
        printf("Stack empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    idx = q1.front;
    for(i = 0; i < q1.count; i++)
    {
        printf("%d ", q1.arr[idx]);
        idx = (idx + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    int ch, x;
    init(&q1);
    init(&q2);
    while(1)
    {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                if(isempty(&q1))
                    printf("Stack empty\n");
                else
                    printf("%d popped\n", pop());
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
