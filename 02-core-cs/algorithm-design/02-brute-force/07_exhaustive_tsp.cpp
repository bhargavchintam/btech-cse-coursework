// TSP by exhaustive search - fix city 0, try every ordering of the rest. O(n!)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " cost matrix\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<int> city;
    for (int i = 1; i < n; i++)
        city.push_back(i);

    int best = INT_MAX;
    do {
        int cur = 0, from = 0;
        for (int k = 0; k < (int)city.size(); k++) {
            cur += cost[from][city[k]];
            from = city[k];
        }
        cur += cost[from][0];              // close the tour back to the start
        if (cur < best)
            best = cur;
    } while (next_permutation(city.begin(), city.end()));   // dont run this for big n

    cout << "Minimum tour cost = " << best << endl;
    return 0;
}
