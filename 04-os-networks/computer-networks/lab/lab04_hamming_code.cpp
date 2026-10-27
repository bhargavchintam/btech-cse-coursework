// lab 4 - Hamming code generation and single bit error correction
// parity bits go at positions 1,2,4,8... and cover the positions whose index has
// that bit set (even parity). we flip one bit to fake a transmission error, then
// the syndrome recomputed at the receiver points straight at the wrong bit.
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string show(const vector<int> &code, int n)
{
    string s;
    for(int p = 1; p <= n; p++) s += (char)('0' + code[p]);
    return s;
}

int main()
{
    string data;
    cout << "enter data bits: ";
    cin >> data;
    int m = data.size();

    int r = 0;
    while((1 << r) < m + r + 1) r++;
    int n = m + r;

    vector<int> code(n + 1, 0);          // 1-indexed
    int k = 0;
    for(int p = 1; p <= n; p++)
        if(p & (p - 1)) code[p] = data[k++] - '0';   // not a power of two -> data bit

    for(int i = 0; i < r; i++){
        int pos = 1 << i, par = 0;
        for(int p = 1; p <= n; p++)
            if(p & pos) par ^= code[p];
        code[pos] = par;
    }
    cout << "hamming code: " << show(code, n) << "\n";

    int err = (5 <= n) ? 5 : 1;
    code[err] ^= 1;
    cout << "with error at " << err << ": " << show(code, n) << "\n";

    int syn = 0;
    for(int i = 0; i < r; i++){
        int pos = 1 << i, par = 0;
        for(int p = 1; p <= n; p++)
            if(p & pos) par ^= code[p];
        if(par) syn += pos;
    }
    cout << "syndrome = " << syn << "\n";
    if(syn) code[syn] ^= 1;
    cout << "corrected:    " << show(code, n) << "\n";
    return 0;
}
