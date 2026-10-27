// stack using linked list - push at head is the top
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = top;
    top = p;
}

void pop() {
    if(top == NULL) {
        printf("stack underflow\n");
        return;
    }
    struct node *t = top;
    printf("popped %d\n", t->data);
    top = top->next;
    free(t);
}

void peek() {
    if(top == NULL) {
        printf("stack empty\n");
        return;
    }
    printf("top = %d\n", top->data);
}

void display() {
    if(top == NULL) {
        printf("stack empty\n");
        return;
    }
    struct node *t = top;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
