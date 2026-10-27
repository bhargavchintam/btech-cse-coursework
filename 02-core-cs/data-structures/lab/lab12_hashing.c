/* Lab Program 12
   Implement a hash table using linear probing for collision resolution.
   Support insert, search and display. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int table[SIZE];

void init()
{
    int i;
    for (i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int i = 0, pos;
    while (i < SIZE) {
        pos = (index + i) % SIZE;
        if (table[pos] == -1) {
            table[pos] = key;
            printf("%d inserted at index %d\n", key, pos);
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}

void search(int key)
{
    int index = key % SIZE;
    int i = 0, pos;
    while (i < SIZE) {
        pos = (index + i) % SIZE;
        if (table[pos] == key) {
            printf("%d found at index %d\n", key, pos);
            return;
        }
        if (table[pos] == -1)
            break;
        i++;
    }
    printf("%d not found\n", key);
}

void display()
{
    int i;
    printf("Index\tValue\n");
    for (i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, table[i]);
    }
}

int main()
{
    int choice, key;
    init();
    while (1) {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
