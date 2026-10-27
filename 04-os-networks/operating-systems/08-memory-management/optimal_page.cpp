// optimal page replacement.  c++ -std=c++11 optimal_page.cpp -o opt && ./opt
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int f, n;
    cout << "number of frames: "; cin >> f;
    cout << "length of reference string: "; cin >> n;
    vector<int> ref(n);
    for(int i = 0; i < n; i++) cin >> ref[i];

    vector<int> frame;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        if(find(frame.begin(), frame.end(), ref[i]) != frame.end())
            continue;
        faults++;
        if((int)frame.size() < f)
            frame.push_back(ref[i]);
        else
        {
            int victim = -1, farthest = -1;
            for(int j = 0; j < f; j++)
            {
                int next = n;            // not used again -> farthest
                for(int k = i + 1; k < n; k++)
                    if(ref[k] == frame[j]){ next = k; break; }
                if(next > farthest){ farthest = next; victim = j; }
            }
            frame[victim] = ref[i];
        }
    }
    cout << "page faults = " << faults << "\n";
    return 0;
}
