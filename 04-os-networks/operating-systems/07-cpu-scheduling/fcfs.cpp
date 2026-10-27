// FCFS CPU scheduling.  c++ -std=c++11 fcfs.cpp -o fcfs && ./fcfs
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Proc { int pid, at, bt, ct, wt, tat; };

int main()
{
    int n;
    cout << "enter number of processes: ";
    cin >> n;
    vector<Proc> p(n);
    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "arrival and burst for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
    }
    sort(p.begin(), p.end(), [](Proc a, Proc b){ return a.at < b.at; });

    int t = 0;
    double sw = 0, st = 0;
    for(int i = 0; i < n; i++)
    {
        if(t < p[i].at) t = p[i].at;
        p[i].ct = t + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        t = p[i].ct;
        sw += p[i].wt; st += p[i].tat;
    }
    cout << "PID  AT  BT  CT  TAT  WT\n";
    for(auto &x : p)
        cout << " P" << x.pid << "   " << x.at << "   " << x.bt << "   "
             << x.ct << "   " << x.tat << "   " << x.wt << "\n";
    cout << "avg WT = " << sw / n << ", avg TAT = " << st / n << "\n";
    return 0;
}
