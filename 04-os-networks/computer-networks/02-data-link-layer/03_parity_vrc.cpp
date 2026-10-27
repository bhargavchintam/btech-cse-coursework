// even / odd parity (VRC) - generate the parity bit and check

#include<iostream>
#include<string>
using namespace std;

int ones(const string& s){
    int c=0;
    for(size_t i=0;i<s.size();i++) if(s[i]=='1') c++;
    return c;
}

int main(){
    string data;
    cout<<"enter data bits: ";
    cin>>data;

    int n = ones(data);
    char even = (n%2==0) ? '0' : '1';
    char odd  = (n%2==0) ? '1' : '0';

    cout<<"even parity: "<<even<<"  -> "<<data<<even<<"\n";
    cout<<"odd  parity: "<<odd <<"  -> "<<data<<odd <<"\n";

    string recv = data + even;
    cout<<"check "<<recv<<" (even) : "<<(ones(recv)%2==0 ? "ok":"error")<<"\n";
    return 0;
}
