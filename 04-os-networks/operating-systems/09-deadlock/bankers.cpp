// banker's algorithm - deadlock avoidance, finds a safe sequence
// c++ -std=c++11 bankers.cpp -o bankers && ./bankers
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cout << "processes and resources: ";
    cin >> n >> m;
    vector<vector<int>> alloc(n, vector<int>(m)), mx(n, vector<int>(m)), need(n, vector<int>(m));
    vector<int> avail(m);

    cout << "allocation matrix:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> alloc[i][j];
    cout << "max matrix:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mx[i][j];
    cout << "available:\n";
    for(int j = 0; j < m; j++) cin >> avail[j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = mx[i][j] - alloc[i][j];

    vector<int> work = avail, seq;
    vector<bool> done(n, false);
    for(int count = 0; count < n; )
    {
        bool progress = false;
        for(int i = 0; i < n; i++)
        {
            if(done[i]) continue;
            bool ok = true;
            for(int j = 0; j < m; j++)
                if(need[i][j] > work[j]){ ok = false; break; }
            if(ok)
            {
                for(int j = 0; j < m; j++) work[j] += alloc[i][j];
                done[i] = true; seq.push_back(i); count++; progress = true;
            }
        }
        if(!progress) break;
    }

    if((int)seq.size() == n)
    {
        cout << "safe, sequence: ";
        for(int i : seq) cout << "P" << i << " ";
        cout << "\n";
    }
    else
        cout << "system is not in a safe state\n";
    return 0;
}
