// huffman coding - build the tree from frequencies and print the codes
#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

struct cmp {
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string code)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        cout << root->ch << "  " << code << "\n";
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, cmp> pq;
    cout << "enter each character and its frequency:\n";
    for(int i = 0; i < n; i++) {
        char c;
        int f;
        cin >> c >> f;
        Node *leaf = new Node;
        leaf->ch = c;
        leaf->freq = f;
        leaf->left = leaf->right = NULL;
        pq.push(leaf);
    }

    while(pq.size() > 1) {
        Node *a = pq.top(); pq.pop();
        Node *b = pq.top(); pq.pop();
        Node *par = new Node;
        par->ch = '*';
        par->freq = a->freq + b->freq;
        par->left = a;
        par->right = b;
        pq.push(par);
    }

    cout << "huffman codes:\n";
    printCodes(pq.top(), "");
    return 0;
}
