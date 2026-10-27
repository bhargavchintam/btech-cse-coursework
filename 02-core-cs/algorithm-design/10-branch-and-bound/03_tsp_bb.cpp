// travelling salesman by branch and bound - lower bound from each city's cheapest edge
#include<iostream>
#include<climits>
using namespace std;

int n;
int cost[15][15];
int minOut[15];          // cheapest outgoing edge of each city
bool visited[15];
int best;
int bestPath[15];
int curPath[15];

void solve(int last, int k, int spent)
{
    if(k == n)
    {
        int back = cost[last][0];
        if(back != 0 && spent + back < best)        // close the tour
        {
            best = spent + back;
            for(int i = 0; i < n; i++)
                bestPath[i] = curPath[i];
        }
        return;
    }

    int lb = spent + minOut[last];      // every city still needs one outgoing edge
    for(int i = 0; i < n; i++)
        if(!visited[i])
            lb += minOut[i];
    if(lb >= best)
        return;

    for(int v = 0; v < n; v++)
        if(!visited[v] && cost[last][v] != 0)
        {
            visited[v] = true;
            curPath[k] = v;
            solve(v, k + 1, spent + cost[last][v]);
            visited[v] = false;
        }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "enter cost matrix (0 = no direct edge):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    for(int i = 0; i < n; i++)
    {
        int mn = INT_MAX;
        for(int j = 0; j < n; j++)
            if(i != j && cost[i][j] != 0 && cost[i][j] < mn)
                mn = cost[i][j];
        minOut[i] = (mn == INT_MAX ? 0 : mn);
    }

    for(int i = 0; i < n; i++)
        visited[i] = false;
    visited[0] = true;
    curPath[0] = 0;
    best = INT_MAX;

    solve(0, 1, 0);

    if(best == INT_MAX)
        cout << "no tour exists\n";
    else
    {
        cout << "minimum tour cost = " << best << "\n";
        cout << "tour: ";
        for(int i = 0; i < n; i++)
            cout << bestPath[i] << " -> ";
        cout << "0\n";
    }
    return 0;
}
