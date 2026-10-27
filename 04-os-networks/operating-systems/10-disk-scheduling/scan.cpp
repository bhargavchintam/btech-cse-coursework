// SCAN (elevator) disk scheduling, moving up first.  c++ -std=c++11 scan.cpp -o scan && ./scan
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    int n, head, size;
    cout << "number of requests: "; cin >> n;
    vector<int> r(n);
    cout << "requests: ";
    for(int i = 0; i < n; i++) cin >> r[i];
    cout << "head start: "; cin >> head;
    cout << "disk size: "; cin >> size;

    sort(r.begin(), r.end());
    int total = 0, cur = head;
    // go up to the end, then reverse
    for(int i = 0; i < n; i++)
        if(r[i] >= head){ total += abs(r[i] - cur); cur = r[i]; }
    total += abs((size - 1) - cur);      // reach the end
    cur = size - 1;
    for(int i = n - 1; i >= 0; i--)
        if(r[i] < head){ total += abs(cur - r[i]); cur = r[i]; }
    cout << "total head movement = " << total << "\n";
    return 0;
}
