// frequency of each element in an array
#include<stdio.h>
int main()
{
    int a[50], visited[50], n, i, j, count;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
        visited[i] = 0;
    for(i=0;i<n;i++)
    {
        if(visited[i] == 1)
            continue;
        count = 1;
        for(j=i+1;j<n;j++)
        {
            if(a[i] == a[j])
            {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d occurs %d times\n", a[i], count);
    }
    return 0;
}
