// count element frequencies using a hash table
#include<stdio.h>
#define SIZE 100

int keys[SIZE];
int cnt[SIZE];
int used[SIZE];

// find the slot for key (existing one, or the first free one)
int find_slot(int key)
{
    int h = ((key % SIZE) + SIZE) % SIZE;
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        j = (h + i) % SIZE;
        if(!used[j] || keys[j] == key)
            return j;
    }
    return -1;
}

int main()
{
    int a[SIZE], n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        j = find_slot(a[i]);
        if(!used[j])
        {
            used[j] = 1;
            keys[j] = a[i];
            cnt[j] = 1;
        }
        else
            cnt[j]++;
    }
    printf("Element : Frequency\n");
    for(i = 0; i < SIZE; i++)
        if(used[i])
            printf("%d : %d\n", keys[i], cnt[i]);
    return 0;
}
