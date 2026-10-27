// travelling salesman - nearest neighbour heuristic
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[20][20];
    cout << "enter the cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    bool visited[20] = {};
    int tour[21];
    int start = 0;
    visited[start] = true;
    tour[0] = start;

    int total = 0;
    int cur = start;
    for(int step = 1; step < n; step++)
    {
        int next = -1, best = 9999;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && cost[cur][j] < best)
            {
                best = cost[cur][j];
                next = j;
            }
        }
        visited[next] = true;
        tour[step] = next;
        total += best;
        cur = next;
    }
    total += cost[cur][start];
    tour[n] = start;

    cout << "tour: ";
    for(int i = 0; i <= n; i++)
    {
        cout << tour[i];
        if(i < n)
            cout << " -> ";
    }
    cout << "\ntotal cost = " << total << endl;
    return 0;
}
