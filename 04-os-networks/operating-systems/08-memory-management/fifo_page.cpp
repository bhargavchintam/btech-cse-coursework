// FIFO page replacement.  c++ -std=c++11 fifo_page.cpp -o fifo && ./fifo
#include<iostream>
#include<vector>
#include<queue>
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
    queue<int> order;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        if(find(frame.begin(), frame.end(), ref[i]) == frame.end())
        {
            faults++;
            if((int)frame.size() < f)
                frame.push_back(ref[i]);
            else
            {
                int old = order.front(); order.pop();
                *find(frame.begin(), frame.end(), old) = ref[i];
            }
            order.push(ref[i]);
        }
    }
    cout << "page faults = " << faults << "\n";
    return 0;
}
