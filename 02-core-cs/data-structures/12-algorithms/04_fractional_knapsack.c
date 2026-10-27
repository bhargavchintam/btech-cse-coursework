// fractional knapsack - greedy by value/weight ratio
#include<stdio.h>

int main()
{
    int n, i, j;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[100], v[100];
    printf("Enter weight and value of each item:\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &w[i], &v[i]);

    int cap;
    printf("Enter capacity: ");
    scanf("%d", &cap);

    // sort items by value/weight ratio, highest first
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            double r1 = (double)v[j] / w[j];
            double r2 = (double)v[j + 1] / w[j + 1];
            if(r1 < r2)
            {
                int t = w[j]; w[j] = w[j + 1]; w[j + 1] = t;
                t = v[j]; v[j] = v[j + 1]; v[j + 1] = t;
            }
        }
    }

    double profit = 0;
    for(i = 0; i < n; i++)
    {
        if(w[i] <= cap)
        {
            cap = cap - w[i];
            profit = profit + v[i];
        }
        else
        {
            profit = profit + v[i] * ((double)cap / w[i]);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);
    return 0;
}
