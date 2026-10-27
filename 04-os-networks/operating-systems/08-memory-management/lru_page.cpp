// LRU page replacement.  c++ -std=c++11 lru_page.cpp -o lru && ./lru
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

    vector<int> frame, used;             // used[j] = last time frame[j] was referenced
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = find(frame.begin(), frame.end(), ref[i]);
        if(it != frame.end())
            used[it - frame.begin()] = i;
        else
        {
            faults++;
            if((int)frame.size() < f)
            {
                frame.push_back(ref[i]);
                used.push_back(i);
            }
            else
            {
                int lru = 0;
                for(int j = 1; j < f; j++)
                    if(used[j] < used[lru]) lru = j;
                frame[lru] = ref[i];
                used[lru] = i;
            }
        }
    }
    cout << "page faults = " << faults << "\n";
    return 0;
}
