// hash table with separate chaining
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node
{
    int key;
    struct node *next;
};

struct node *table[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int h = hash(key);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->key = key;
    p->next = table[h];     // add at front of the chain
    table[h] = p;
    printf("%d inserted at index %d\n", key, h);
}

int search(int key)
{
    struct node *p = table[hash(key)];
    while(p != NULL)
    {
        if(p->key == key)
            return 1;
        p = p->next;
    }
    return 0;
}

void display()
{
    int i;
    struct node *p;
    for(i = 0; i < SIZE; i++)
    {
        printf("[%d]: ", i);
        p = table[i];
        while(p != NULL)
        {
            printf("%d -> ", p->key);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int ch, key;
    while(1)
    {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                if(search(key))
                    printf("%d found\n", key);
                else
                    printf("%d not found\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;    // TODO free the chains before exit
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
