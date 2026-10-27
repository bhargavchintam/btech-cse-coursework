// LOOK disk scheduling, moving up first (no going to the disk end).  c++ -std=c++11 look.cpp -o look && ./look
#include<iostream>
#include<vector>
#include<algorithm>
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

    sort(r.begin(), r.end());
    int total = 0, cur = head;
    for(int i = 0; i < n; i++)
        if(r[i] >= head){ total += abs(r[i] - cur); cur = r[i]; }
    for(int i = n - 1; i >= 0; i--)
        if(r[i] < head){ total += abs(cur - r[i]); cur = r[i]; }
    cout << "total head movement = " << total << "\n";
    return 0;
}
