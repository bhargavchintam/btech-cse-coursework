// job sequencing with deadlines - greedy
#include<stdio.h>

typedef struct
{
    char id[10];
    int deadline;
    int profit;
} JOB;

int main()
{
    int n, i, j;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    JOB jobs[100];
    printf("Enter id, deadline and profit of each job:\n");
    for(i = 0; i < n; i++)
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

    // sort by profit, highest first
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(jobs[j].profit < jobs[j + 1].profit)
            {
                JOB t = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = t;
            }
        }
    }

    int maxd = 0;
    for(i = 0; i < n; i++)
        if(jobs[i].deadline > maxd)
            maxd = jobs[i].deadline;

    int slot[100];
    for(i = 0; i <= maxd; i++)
        slot[i] = -1;

    int profit = 0;
    for(i = 0; i < n; i++)
    {
        for(j = jobs[i].deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                profit = profit + jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled jobs: ");
    for(i = 1; i <= maxd; i++)
        if(slot[i] != -1)
            printf("%s ", jobs[slot[i]].id);
    printf("\n");
    printf("Total profit = %d\n", profit);
    return 0;
}
