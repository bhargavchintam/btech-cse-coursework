// SJF (non-preemptive) scheduling.  c++ -std=c++11 sjf.cpp -o sjf && ./sjf
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Proc { int pid, bt, wt, tat; };

int main()
{
    int n;
    cout << "enter number of processes: ";
    cin >> n;
    vector<Proc> p(n);
    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "burst for P" << i + 1 << ": ";
        cin >> p[i].bt;
    }
    sort(p.begin(), p.end(), [](Proc a, Proc b){ return a.bt < b.bt; });

    int t = 0;
    double sw = 0, st = 0;
    for(int i = 0; i < n; i++)
    {
        p[i].wt = t;
        t += p[i].bt;
        p[i].tat = t;
        sw += p[i].wt; st += p[i].tat;
    }
    cout << "order: ";
    for(auto &x : p) cout << "P" << x.pid << " ";
    cout << "\navg WT = " << sw / n << ", avg TAT = " << st / n << "\n";
    return 0;
}
