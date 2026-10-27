/* Lab Program 8
   Implement both a stack and a queue using linked lists in a single program.
   Stack uses push/pop, queue uses insert/delete at the two ends. */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *top = NULL;
NODE *front = NULL, *rear = NULL;

void push(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("%d pushed\n", x);
}

void pop()
{
    NODE *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("%d popped\n", temp->data);
    top = top->next;
    free(temp);
}

void stack_display()
{
    NODE *ptr = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d inserted\n", x);
}

void dequeue()
{
    NODE *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("%d deleted\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void queue_display()
{
    NODE *ptr = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1) {
        printf("\n1.Push  2.Pop  3.Stack Display  4.Enqueue  5.Dequeue  6.Queue Display  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                stack_display();
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                queue_display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
