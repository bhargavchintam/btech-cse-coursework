// linked queue - insert at rear, delete from front
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d inserted\n", x);
}

void dequeue() {
    struct node *temp;
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

void display() {
    struct node *ptr = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
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
