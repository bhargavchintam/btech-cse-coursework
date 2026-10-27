/* Lab Program 10
   Fractional knapsack by the greedy method. Sort the items by value/weight
   ratio and keep filling the sack, taking a fraction of the last item if it
   does not fit whole. */
#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
    int val, wt;
};

bool byRatio(const Item &a, const Item &b)
{
    return (double)a.val / a.wt > (double)b.val / b.wt;
}

int main()
{
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = 3, W = 50;

    sort(items, items + n, byRatio);

    double total = 0;
    int cap = W;
    for (int i = 0; i < n && cap > 0; i++) {
        if (items[i].wt <= cap) {
            total += items[i].val;
            cap -= items[i].wt;
        } else {
            total += items[i].val * ((double)cap / items[i].wt);
            cap = 0;
        }
    }

    cout << "maximum value = " << total << "\n";
    return 0;
}
