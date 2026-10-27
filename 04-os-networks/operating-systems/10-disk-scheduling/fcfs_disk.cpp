// FCFS disk scheduling.  c++ -std=c++11 fcfs_disk.cpp -o fcfs && ./fcfs
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int main()
{
    int n, head;
    cout << "number of requests: "; cin >> n;
    vector<int> r(n);
    cout << "requests: ";
    for(int i = 0; i < n; i++) cin >> r[i];
    cout << "head start: "; cin >> head;

    int total = 0, cur = head;
    for(int i = 0; i < n; i++)
    {
        total += abs(r[i] - cur);
        cur = r[i];
    }
    cout << "total head movement = " << total << "\n";
    return 0;
}
