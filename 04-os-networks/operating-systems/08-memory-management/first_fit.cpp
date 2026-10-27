// first fit memory allocation.  c++ -std=c++11 first_fit.cpp -o ff && ./ff
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
    vector<int> proc(n), alloc(n, -1);
    for(int i = 0; i < n; i++){ cout << "process " << i + 1 << " size: "; cin >> proc[i]; }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(block[j] >= proc[i])
            {
                alloc[i] = j;
                block[j] -= proc[i];
                break;
            }
    for(int i = 0; i < n; i++)
        if(alloc[i] != -1)
            cout << "P" << i + 1 << " (" << proc[i] << ") -> block " << alloc[i] + 1 << "\n";
        else
            cout << "P" << i + 1 << " (" << proc[i] << ") -> not allocated\n";
    return 0;
}
