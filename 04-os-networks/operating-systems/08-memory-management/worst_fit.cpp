// worst fit memory allocation.  c++ -std=c++11 worst_fit.cpp -o wf && ./wf
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m, n;
    cout << "number of blocks: "; cin >> m;
    vector<int> block(m);
    for(int i = 0; i < m; i++){ cout << "block " << i + 1 << " size: "; cin >> block[i]; }
    cout << "number of processes: "; cin >> n;
    vector<int> proc(n);
    for(int i = 0; i < n; i++){ cout << "process " << i + 1 << " size: "; cin >> proc[i]; }

    for(int i = 0; i < n; i++)
    {
        int worst = -1;
        for(int j = 0; j < m; j++)
            if(block[j] >= proc[i] && (worst == -1 || block[j] > block[worst]))
                worst = j;
        if(worst != -1)
        {
            cout << "P" << i + 1 << " (" << proc[i] << ") -> block " << worst + 1 << "\n";
            block[worst] -= proc[i];
        }
        else
            cout << "P" << i + 1 << " (" << proc[i] << ") -> not allocated\n";
    }
    return 0;
}
