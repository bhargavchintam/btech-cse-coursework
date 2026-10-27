// remove duplicates from an array using hashing
#include<stdio.h>
#define SIZE 100

int seen[SIZE];
int used[SIZE];

int hash(int key)
{
    return ((key % SIZE) + SIZE) % SIZE;
}

// returns 1 if key is new, 0 if it was already seen
int add(int key)
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (hash(key) + i) % SIZE;
        if(!used[j])
        {
            used[j] = 1;
            seen[j] = key;
            return 1;
        }
        if(seen[j] == key)
            return 0;
    }
    return 0;
}

int main()
{
    int a[SIZE], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("After removing duplicates : ");
    for(i = 0; i < n; i++)
        if(add(a[i]))
            printf("%d ", a[i]);
    printf("\n");
    return 0;
}
