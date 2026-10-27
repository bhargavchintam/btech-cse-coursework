// fractional knapsack - greedy by value/weight ratio
#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
    int weight, value;
};

// highest value/weight ratio first, so sort descending on the ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];
    cout << "enter weight and value of each item:\n";
    for(int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;

    int cap;
    cout << "Enter knapsack capacity: ";
    cin >> cap;

    sort(items, items + n, cmp);

    double total = 0;
    int left = cap;
    for(int i = 0; i < n; i++) {
        if(items[i].weight <= left) {
            total += items[i].value;
            left -= items[i].weight;
        } else {
            total += items[i].value * ((double)left / items[i].weight);
            break;
        }
    }

    cout << "maximum value = " << total << endl;
    return 0;
}
