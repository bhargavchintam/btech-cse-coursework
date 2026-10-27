// Hamming - receive a codeword with a single bit error, find it with the syndrome

#include<iostream>
#include<string>
using namespace std;

int main(){
    string c;
    cout<<"enter received codeword: ";
    cin>>c;

    int n = c.size();
    int r = 0;
    while((1<<r) < n+1) r++;

    int synd = 0;
    for(int i=0;i<r;i++){
        int p = 1<<i, s=0;
        for(int pos=1;pos<=n;pos++)
            if(pos & p) s ^= (c[pos-1]-'0');
        if(s) synd += p;                   // this parity check failed
    }

    if(synd==0) cout<<"no error\n";
    else{
        cout<<"error at position "<<synd<<"\n";
        c[synd-1] = (c[synd-1]=='0') ? '1' : '0';
        cout<<"corrected: "<<c<<"\n";
    }
    return 0;
}
