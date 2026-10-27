// rail fence cipher - write in a zigzag over r rails, read row by row
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string encrypt(string s, int r)
{
    if (r == 1) return s;
    vector<string> rail(r);
    int row = 0, dir = 1;
    for (char c : s) {
        rail[row] += c;
        if (row == 0) dir = 1;
        else if (row == r - 1) dir = -1;
        row += dir;
    }
    string out;
    for (int i = 0; i < r; i++)
        out += rail[i];
    return out;
}

string decrypt(string s, int r)
{
    if (r == 1) return s;
    int n = s.size();
    vector<int> row(n);
    int cur = 0, dir = 1;
    for (int i = 0; i < n; i++) {           // mark which rail each position sits on
        row[i] = cur;
        if (cur == 0) dir = 1;
        else if (cur == r - 1) dir = -1;
        cur += dir;
    }
    string out(n, ' ');
    int k = 0;
    for (int rr = 0; rr < r; rr++)
        for (int i = 0; i < n; i++)
            if (row[i] == rr)
                out[i] = s[k++];
    return out;
}

int main()
{
    string msg;
    int r;
    cout << "Enter message: ";
    getline(cin, msg);
    cout << "Enter number of rails: ";
    cin >> r;

    string c = encrypt(msg, r);
    cout << "Encrypted: " << c << "\n";
    cout << "Decrypted: " << decrypt(c, r) << "\n";
    return 0;
}
