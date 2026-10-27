// closed hashing (open addressing) with linear probing, keys assumed >= 0
#include<iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;                  // -1 marks an empty slot
}

void insert(int k)
{
    int h = k % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int slot = (h + i) % SIZE;
        if (table[slot] == -1) {
            table[slot] = k;
            return;
        }
    }
    cout << "table full, cannot insert " << k << "\n";
}

int search(int k)
{
    int h = k % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int slot = (h + i) % SIZE;
        if (table[slot] == -1)
            return -1;                  // hit an empty slot, key is not here
        if (table[slot] == k)
            return slot;
    }
    return -1;
}

void display()
{
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (table[i] == -1)
            cout << "-\n";
        else
            cout << table[i] << "\n";
    }
}

int main()
{
    init();
    int n;
    cout << "Enter number of keys: ";
    cin >> n;
    cout << "Enter " << n << " keys\n";
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        insert(k);
    }

    display();

    int q;
    while (true) {
        cout << "Search key (-1 to stop): ";
        if (!(cin >> q) || q == -1)
            break;
        int pos = search(q);
        if (pos != -1)
            cout << q << " found at slot " << pos << "\n";
        else
            cout << q << " not found\n";
    }
    return 0;
}
