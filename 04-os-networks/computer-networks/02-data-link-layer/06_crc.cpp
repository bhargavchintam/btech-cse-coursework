/* Bindu Bhargava   14-09-19 */
// CRC using mod-2 division, generator = CRC-CCITT (x^16 + x^12 + x^5 + 1)

#include<iostream>
#include<string>
using namespace std;

string gen = "10001000000100001";

string xorstr(const string& a, const string& b){   // drops the leading bit
    string r;
    for(size_t i=1;i<b.size();i++) r += (a[i]==b[i]) ? '0' : '1';
    return r;
}

string divide(const string& dividend){
    size_t n = gen.size();
    string tmp = dividend.substr(0, n);
    size_t pick = n;
    while(pick < dividend.size()){
        if(tmp[0]=='1') tmp = xorstr(gen, tmp) + dividend[pick];
        else            tmp = xorstr(string(n,'0'), tmp) + dividend[pick];
        pick++;
    }
    if(tmp[0]=='1') tmp = xorstr(gen, tmp);
    else            tmp = xorstr(string(n,'0'), tmp);
    return tmp;                                       // n-1 bit remainder
}

int main(){
    string data = "1101011011";
    string aug  = data + string(gen.size()-1, '0');

    string rem  = divide(aug);
    string code = data + rem;
    cout<<"data     : "<<data<<"\n";
    cout<<"remainder: "<<rem<<"\n";
    cout<<"codeword : "<<code<<"\n";

    cout<<"receiver (clean) : "<<divide(code)
        <<(divide(code)==string(gen.size()-1,'0') ? "  no error":"  ERROR")<<"\n";

    string bad = code;
    bad[4] = (bad[4]=='0') ? '1' : '0';               // flip one bit in transit
    cout<<"receiver (error) : "<<divide(bad)
        <<(divide(bad)==string(gen.size()-1,'0') ? "  no error":"  ERROR")<<"\n";
    return 0;
}
