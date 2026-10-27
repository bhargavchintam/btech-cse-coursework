/* Lab Program 7
   All pairs shortest paths of a directed weighted graph using the
   Floyd-Warshall algorithm. INF marks a missing edge. */
#include<iostream>
using namespace std;

const int N = 4;
const int INF = 1000000000;

int d[N][N] = {
    {0, 3, INF, 7},
    {8, 0, 2, INF},
    {5, INF, 0, 1},
    {2, INF, INF, 0}
};

int main()
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    cout << "all pairs shortest distances:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << d[i][j] << "\t";
        cout << "\n";
    }
    return 0;
}
