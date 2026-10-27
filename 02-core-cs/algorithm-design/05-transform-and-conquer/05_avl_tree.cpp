// AVL tree - self balancing BST, keeps height O(log n) with four rotations
#include<iostream>
using namespace std;

struct Node {
    int key, ht;
    Node *left, *right;
    Node(int k) : key(k), ht(1), left(NULL), right(NULL) {}
};

int height(Node* p) { return p ? p->ht : 0; }

int balance(Node* p) { return p ? height(p->left) - height(p->right) : 0; }

void fix(Node* p)
{
    int hl = height(p->left), hr = height(p->right);
    p->ht = 1 + (hl > hr ? hl : hr);
}

Node* rotateRight(Node* y)
{
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    fix(y); fix(x);
    return x;
}

Node* rotateLeft(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    fix(x); fix(y);
    return y;
}

Node* insert(Node* root, int key)
{
    if (!root) return new Node(key);
    if (key < root->key)      root->left  = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;

    fix(root);
    int b = balance(root);

    if (b > 1 && key < root->left->key)  return rotateRight(root);          // LL
    if (b < -1 && key > root->right->key) return rotateLeft(root);          // RR
    if (b > 1 && key > root->left->key) {                                   // LR
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (b < -1 && key < root->right->key) {                                 // RL
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void inorder(Node* p)
{
    if (!p) return;
    inorder(p->left);
    cout << p->key << " ";
    inorder(p->right);
}

void preorder(Node* p)
{
    if (!p) return;
    cout << p->key << " ";
    preorder(p->left);
    preorder(p->right);
}

int main()
{
    int n;
    cout << "Enter number of keys: ";
    cin >> n;
    cout << "Enter " << n << " keys\n";
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        root = insert(root, k);
    }

    cout << "inorder  : ";
    inorder(root);
    cout << "\npreorder : ";
    preorder(root);
    cout << "\nroot = " << root->key << "  (tree stays balanced)\n";
    return 0;
}
