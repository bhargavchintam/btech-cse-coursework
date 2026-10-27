// hash table - quadratic probing
#include<stdio.h>
#define SIZE 10

int table[SIZE];
int occ[SIZE];

void insert(int key)
{
    int h = key % SIZE, i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (h + i*i) % SIZE;
        if(!occ[j])
        {
            table[j] = key;
            occ[j] = 1;
            printf("%d placed at index %d\n", key, j);
            return;
        }
    }
    printf("Could not place %d\n", key);
}

int search(int key)
{
    int h = key % SIZE, i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (h + i*i) % SIZE;
        if(occ[j] && table[j] == key)
            return j;
    }
    return -1;
}

void display()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        if(occ[i])
            printf("[%d] %d\n", i, table[i]);
        else
            printf("[%d] --\n", i);
    }
}

int main()
{
    int ch, key, idx;
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
                idx = search(key);
                if(idx == -1)
                    printf("%d not found\n", key);
                else
                    printf("%d found at index %d\n", key, idx);
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
