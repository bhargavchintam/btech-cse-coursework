// Round Robin scheduling.  c++ -std=c++11 round_robin.cpp -o rr && ./rr
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n, q;
    cout << "enter number of processes: ";
    cin >> n;
    vector<int> bt(n), rem(n), wt(n, 0), tat(n);
    for(int i = 0; i < n; i++)
    {
        cout << "burst for P" << i + 1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];
    }
    cout << "time quantum: ";
    cin >> q;

    queue<int> ready;
    for(int i = 0; i < n; i++) ready.push(i);
    int t = 0;
    while(!ready.empty())
    {
        int i = ready.front(); ready.pop();
        int run = min(q, rem[i]);
        t += run;
        rem[i] -= run;
        if(rem[i] == 0)
            tat[i] = t;
        else
            ready.push(i);
    }
    double sw = 0, st = 0;
    for(int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        sw += wt[i]; st += tat[i];
    }
    for(int i = 0; i < n; i++)
        cout << "P" << i + 1 << " WT=" << wt[i] << " TAT=" << tat[i] << "\n";
    cout << "avg WT = " << sw / n << ", avg TAT = " << st / n << "\n";
    return 0;
}
