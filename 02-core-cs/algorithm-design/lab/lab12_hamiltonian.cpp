/* Lab Program 12
   Hamiltonian cycle by backtracking. Find a cycle that starts at vertex 0,
   visits every vertex exactly once and returns to 0. Graph is an undirected
   adjacency matrix. */
#include<iostream>
using namespace std;

const int N = 5;

int g[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[N];

bool solve(int pos)
{
    if (pos == N)
        return g[path[pos-1]][path[0]] == 1;

    for (int v = 1; v < N; v++) {
        bool used = false;
        for (int k = 0; k < pos; k++)
            if (path[k] == v) used = true;
        if (!used && g[path[pos-1]][v]) {
            path[pos] = v;
            if (solve(pos+1)) return true;
        }
    }
    return false;
}

int main()
{
    path[0] = 0;
    if (solve(1)) {
        cout << "hamiltonian cycle:\n";
        for (int i = 0; i < N; i++) cout << path[i] << " -> ";
        cout << path[0] << "\n";
    } else {
        cout << "no hamiltonian cycle exists\n";
    }
    return 0;
}
