// SSTF disk scheduling (shortest seek time first).  c++ -std=c++11 sstf.cpp -o sstf && ./sstf
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int main()
{
    int n, head;
    cout << "number of requests: "; cin >> n;
    vector<int> r(n);
    vector<bool> done(n, false);
    cout << "requests: ";
    for(int i = 0; i < n; i++) cin >> r[i];
    cout << "head start: "; cin >> head;

    int total = 0, cur = head;
    for(int k = 0; k < n; k++)
    {
        int best = -1;
        for(int i = 0; i < n; i++)
            if(!done[i] && (best == -1 || abs(r[i] - cur) < abs(r[best] - cur)))
                best = i;
        total += abs(r[best] - cur);
        cur = r[best];
        done[best] = true;
    }
    cout << "total head movement = " << total << "\n";
    return 0;
}
