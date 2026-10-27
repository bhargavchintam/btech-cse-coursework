// Hamming code - generate the codeword, parity bits sit at the powers of 2

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string d;
    cout<<"enter data bits: ";
    cin>>d;

    int m = d.size();
    int r = 0;
    while((1<<r) < m + r + 1) r++;
    int n = m + r;

    vector<char> code(n+1, '0');           // 1-indexed, position 1 is leftmost
    int j = 0;
    for(int pos=1; pos<=n; pos++)
        if(pos & (pos-1))                  // not a power of 2 -> data bit
            code[pos] = d[j++];

    for(int i=0;i<r;i++){
        int p = 1<<i, s=0;
        for(int pos=1;pos<=n;pos++)
            if(pos & p) s ^= (code[pos]-'0');
        code[p] = s ? '1' : '0';           // even parity
    }

    cout<<"r = "<<r<<", codeword ("<<n<<" bits): ";
    for(int pos=1;pos<=n;pos++) cout<<code[pos];
    cout<<"\n";
    return 0;
}
