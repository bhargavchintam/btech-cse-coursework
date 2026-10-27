// deadlock detection - given allocation and request, find deadlocked processes
// c++ -std=c++11 deadlock_detection.cpp -o dd && ./dd
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cout << "processes and resources: ";
    cin >> n >> m;
    vector<vector<int>> alloc(n, vector<int>(m)), req(n, vector<int>(m));
    vector<int> avail(m);
    cout << "allocation:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> alloc[i][j];
    cout << "request:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> req[i][j];
    cout << "available:\n";
    for(int j = 0; j < m; j++) cin >> avail[j];

    vector<int> work = avail;
    vector<bool> finish(n);
    for(int i = 0; i < n; i++)
    {
        bool zero = true;
        for(int j = 0; j < m; j++) if(alloc[i][j]) zero = false;
        finish[i] = zero;                // no resources held -> can finish
    }
    for(bool changed = true; changed; )
    {
        changed = false;
        for(int i = 0; i < n; i++)
        {
            if(finish[i]) continue;
            bool ok = true;
            for(int j = 0; j < m; j++) if(req[i][j] > work[j]){ ok = false; break; }
            if(ok)
            {
                for(int j = 0; j < m; j++) work[j] += alloc[i][j];
                finish[i] = true; changed = true;
            }
        }
    }
    bool dead = false;
    cout << "deadlocked processes: ";
    for(int i = 0; i < n; i++)
        if(!finish[i]){ cout << "P" << i << " "; dead = true; }
    cout << (dead ? "\n" : "none\n");
    return 0;
}
