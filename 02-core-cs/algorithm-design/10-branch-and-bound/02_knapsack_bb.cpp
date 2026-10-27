// 0/1 knapsack by branch and bound - upper bound comes from the fractional relaxation
#include<iostream>
#include<algorithm>
using namespace std;

struct Item { int w, v; };

int n, cap;
Item item[50];
int best;

bool byRatio(Item a, Item b)
{
    return (double)a.v / a.w > (double)b.v / b.w;
}

// fill leftover capacity greedily, letting the last item be fractional
double bound(int level, int weight, int value)
{
    double b = value;
    int w = weight;
    for(int i = level; i < n; i++)
    {
        if(w + item[i].w <= cap)
        {
            w += item[i].w;
            b += item[i].v;
        }
        else
        {
            b += (cap - w) * (double)item[i].v / item[i].w;
            break;
        }
    }
    return b;
}

void solve(int level, int weight, int value)
{
    if(value > best)
        best = value;
    if(level == n)
        return;
    if(bound(level, weight, value) <= best)
        return;

    if(weight + item[level].w <= cap)
        solve(level + 1, weight + item[level].w, value + item[level].v);

    solve(level + 1, weight, value);
}

int main()
{
    cout << "Enter number of items and capacity: ";
    cin >> n >> cap;
    cout << "enter weight and value of each item:\n";
    for(int i = 0; i < n; i++)
        cin >> item[i].w >> item[i].v;

    sort(item, item + n, byRatio);      // process by value/weight so the bound is tight

    best = 0;
    solve(0, 0, 0);

    cout << "maximum value = " << best << endl;
    return 0;
}
