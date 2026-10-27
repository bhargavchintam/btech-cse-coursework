// C-SCAN disk scheduling, moving up then wrapping to 0.  c++ -std=c++11 cscan.cpp -o cscan && ./cscan
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
    for(int i = 0; i < n; i++)
        if(r[i] >= head){ total += abs(r[i] - cur); cur = r[i]; }
    total += abs((size - 1) - cur);      // go to the end
    total += size - 1;                   // wrap 199 -> 0
    cur = 0;
    for(int i = 0; i < n; i++)
        if(r[i] < head){ total += abs(r[i] - cur); cur = r[i]; }
    cout << "total head movement = " << total << "\n";
    return 0;
}
