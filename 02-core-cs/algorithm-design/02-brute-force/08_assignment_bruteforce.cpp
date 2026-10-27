// assignment problem by exhaustive search - every worker->job permutation. O(n!)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of workers/jobs: ";
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " cost matrix (row = worker)\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<int> job(n);
    for (int i = 0; i < n; i++)
        job[i] = i;

    int best = INT_MAX;
    vector<int> bestAssign;
    do {
        int cur = 0;
        for (int i = 0; i < n; i++)
            cur += cost[i][job[i]];
        if (cur < best) {
            best = cur;
            bestAssign = job;
        }
    } while (next_permutation(job.begin(), job.end()));

    cout << "Minimum cost = " << best << endl;
    cout << "Assignment (worker->job): ";
    for (int i = 0; i < n; i++)
        cout << i << "->" << bestAssign[i] << "  ";
    cout << endl;
    return 0;
}
