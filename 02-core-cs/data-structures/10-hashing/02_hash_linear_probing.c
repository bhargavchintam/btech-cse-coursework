// hash table - linear probing with delete
#include<stdio.h>
#define SIZE 10
#define EMPTY 0
#define USED  1
#define DEL   2

int table[SIZE];
int state[SIZE];    // EMPTY, USED or DEL

void insert(int key)
{
    int h = key % SIZE, i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (h + i) % SIZE;
        if(state[j] != USED)
        {
            table[j] = key;
            state[j] = USED;
            printf("%d placed at index %d\n", key, j);
            return;
        }
    }
    printf("Table is full\n");
}

int search(int key)
{
    int h = key % SIZE, i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (h + i) % SIZE;
        if(state[j] == EMPTY)
            return -1;      // a real hole means the key is not here
        if(state[j] == USED && table[j] == key)
            return j;
        // DEL -> keep probing
    }
    return -1;
}

void del(int key)
{
    int idx = search(key);
    if(idx == -1)
        printf("%d not found\n", key);
    else
    {
        state[idx] = DEL;
        printf("%d deleted from index %d\n", key, idx);
    }
}

void display()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        if(state[i] == USED)
            printf("[%d] %d\n", i, table[i]);
        else if(state[i] == DEL)
            printf("[%d] deleted\n", i);
        else
            printf("[%d] empty\n", i);
    }
}

int main()
{
    int ch, key, idx;
    while(1)
    {
        printf("\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\n");
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
                idx = search(key);
                if(idx == -1)
                    printf("%d not found\n", key);
                else
                    printf("%d found at index %d\n", key, idx);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                del(key);
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
