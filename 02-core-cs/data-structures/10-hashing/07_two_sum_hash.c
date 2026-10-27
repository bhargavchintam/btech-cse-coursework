// find a pair that sums to a target using a hash set
#include<stdio.h>
#define SIZE 100

int set[SIZE];
int used[SIZE];

int hash(int key)
{
    return ((key % SIZE) + SIZE) % SIZE;
}

void add(int key)
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (hash(key) + i) % SIZE;
        if(!used[j])
        {
            used[j] = 1;
            set[j] = key;
            return;
        }
    }
}

int contains(int key)
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (hash(key) + i) % SIZE;
        if(!used[j])
            return 0;
        if(set[j] == key)
            return 1;
    }
    return 0;
}

int main()
{
    int a[SIZE], n, i, target, need, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target: ");
    scanf("%d", &target);
    for(i = 0; i < n; i++)
    {
        need = target - a[i];
        if(contains(need))
        {
            printf("Pair found : %d + %d = %d\n", need, a[i], target);
            found = 1;
            break;
        }
        add(a[i]);
    }
    if(!found)
        printf("No pair found\n");
    return 0;
}
