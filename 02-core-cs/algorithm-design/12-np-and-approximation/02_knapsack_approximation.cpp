// 0/1 knapsack - greedy approximation by value/weight ratio
#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int wt, val;
};

bool byRatio(Item a, Item b)
{
    return (double)a.val / a.wt > (double)b.val / b.wt;
}

int main()
{
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[50];
    cout << "enter weight and value of each item:\n";
    for(int i = 0; i < n; i++)
        cin >> items[i].wt >> items[i].val;

    cout << "Enter capacity: ";
    cin >> cap;

    sort(items, items + n, byRatio);

    int value = 0, weight = 0;
    for(int i = 0; i < n; i++)
    {
        if(weight + items[i].wt <= cap)
        {
            weight += items[i].wt;
            value += items[i].val;
        }
    }

    cout << "approximate value = " << value << endl;
    return 0;
}
