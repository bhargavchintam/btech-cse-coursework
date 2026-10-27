// vertex cover - 2-approximation (take both ends of an uncovered edge)
#include<iostream>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    int u[100], v[100];
    bool used[100] = {};
    cout << "enter the edges:\n";
    for(int i = 0; i < e; i++)
        cin >> u[i] >> v[i];

    bool inCover[100] = {};
    for(int i = 0; i < e; i++)
    {
        if(!used[i])
        {
            int a = u[i], b = v[i];
            inCover[a] = true;
            inCover[b] = true;
            for(int j = 0; j < e; j++)
                if(u[j] == a || u[j] == b || v[j] == a || v[j] == b)
                    used[j] = true;
        }
    }

    cout << "vertex cover: ";
    for(int i = 0; i < n; i++)
        if(inCover[i])
            cout << i << " ";
    cout << "\n";
    return 0;
}
