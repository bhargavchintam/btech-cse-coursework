// best fit memory allocation.  c++ -std=c++11 best_fit.cpp -o bf && ./bf
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
        int best = -1;
        for(int j = 0; j < m; j++)
            if(block[j] >= proc[i] && (best == -1 || block[j] < block[best]))
                best = j;
        if(best != -1)
        {
            cout << "P" << i + 1 << " (" << proc[i] << ") -> block " << best + 1 << "\n";
            block[best] -= proc[i];
        }
        else
            cout << "P" << i + 1 << " (" << proc[i] << ") -> not allocated\n";
    }
    return 0;
}
