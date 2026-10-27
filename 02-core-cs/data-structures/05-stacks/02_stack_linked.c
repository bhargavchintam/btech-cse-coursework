// stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("%d pushed\n", x);
}

void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("%d popped\n", temp->data);
    top = top->next;
    free(temp);   // dont forget to free
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top = %d\n", top->data);
}

void display()
{
    struct node *ptr = top;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
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
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
