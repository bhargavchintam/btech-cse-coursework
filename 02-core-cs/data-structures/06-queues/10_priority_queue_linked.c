// priority queue using a sorted linked list - highest priority at the front
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    int prio;
    struct node *next;
} NODE;

NODE *front = NULL;

void insert(int x, int p) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    NODE *ptr;
    temp->data = x;
    temp->prio = p;
    temp->next = NULL;

    if (front == NULL || p > front->prio) {
        temp->next = front;
        front = temp;
    }
    else {
        ptr = front;
        while (ptr->next != NULL && ptr->next->prio >= p)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    printf("Inserted\n");
}

void delete() {
    NODE *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Served %d (priority %d)\n", temp->data, temp->prio);
    front = front->next;
    free(temp);
}

void display() {
    NODE *ptr = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element\tPriority\n");
    while (ptr != NULL) {
        printf("%d\t%d\n", ptr->data, ptr->prio);
        ptr = ptr->next;
    }
}

int main() {
    int ch, x, p;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element and priority: ");
                scanf("%d %d", &x, &p);
                insert(x, p);
                break;
            case 2:
                delete();
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
