// assignment problem by branch and bound - min total cost, one distinct job per worker
#include<iostream>
#include<climits>
using namespace std;

int n;
int cost[20][20];
bool taken[20];          // is this job already assigned
int best;
int bestJob[20];
int curJob[20];

// optimistic cost: what we have spent plus each remaining worker's cheapest free job
int lowerBound(int worker, int spent)
{
    int lb = spent;
    for(int w = worker; w < n; w++)
    {
        int mn = INT_MAX;
        for(int j = 0; j < n; j++)
            if(!taken[j] && cost[w][j] < mn)
                mn = cost[w][j];
        lb += mn;
    }
    return lb;
}

void solve(int worker, int spent)
{
    if(worker == n)
    {
        if(spent < best)
        {
            best = spent;
            for(int i = 0; i < n; i++)
                bestJob[i] = curJob[i];
        }
        return;
    }
    if(lowerBound(worker, spent) >= best)
        return;

    for(int j = 0; j < n; j++)
        if(!taken[j])
        {
            taken[j] = true;
            curJob[worker] = j;
            solve(worker + 1, spent + cost[worker][j]);
            taken[j] = false;
        }
}

int main()
{
    cout << "Enter n (workers = jobs): ";
    cin >> n;
    cout << "enter cost matrix (worker x job):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    for(int i = 0; i < n; i++)
        taken[i] = false;
    best = INT_MAX;

    solve(0, 0);

    cout << "minimum cost = " << best << "\n";
    for(int i = 0; i < n; i++)
        cout << "worker " << i << " -> job " << bestJob[i] << "\n";
    return 0;
}
