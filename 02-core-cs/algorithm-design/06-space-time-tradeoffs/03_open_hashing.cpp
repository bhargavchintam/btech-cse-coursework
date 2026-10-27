// open hashing (separate chaining), h(k) = k % SIZE
#include<iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int key;
    Node *next;
};

Node *table[SIZE] = {};

void insert(int k)
{
    int h = k % SIZE;
    Node *p = new Node;
    p->key = k;
    p->next = table[h];                 // push on the front of the chain
    table[h] = p;
}

bool search(int k)
{
    int h = k % SIZE;
    for (Node *p = table[h]; p != nullptr; p = p->next)
        if (p->key == k)
            return true;
    return false;
}

void display()
{
    for (int i = 0; i < SIZE; i++) {
        cout << i << ":";
        for (Node *p = table[i]; p != nullptr; p = p->next)
            cout << " -> " << p->key;
        cout << "\n";
    }
}

int main()
{
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
        if (search(q))
            cout << q << " found\n";
        else
            cout << q << " not found\n";
    }
    return 0;
}
