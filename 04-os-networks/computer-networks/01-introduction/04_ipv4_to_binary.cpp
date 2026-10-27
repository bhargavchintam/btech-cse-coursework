/* Bindu Bhargava   26-08-19 */
// dotted-decimal IPv4 <-> 32-bit binary, both ways
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string toBits(int x)
{
    string b;
    for(int i=7; i>=0; i--)
        b += ((x >> i) & 1) ? '1' : '0';
    return b;
}

int main()
{
    int choice;
    cout << "1. dotted decimal -> binary\n";
    cout << "2. binary -> dotted decimal\n";
    cout << "choice: ";
    cin >> choice;

    if(choice == 1){
        int a, b, c, d;
        cout << "enter a.b.c.d: ";
        if(scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4){ cout << "bad input\n"; return 1; }
        cout << toBits(a) << "." << toBits(b) << "." << toBits(c) << "." << toBits(d) << "\n";
        // also show it as one 32-bit number
        unsigned long v = ((unsigned long)a<<24) | (b<<16) | (c<<8) | d;
        cout << "32-bit value = " << v << "\n";
    }
    else if(choice == 2){
        string s;
        cout << "enter binary (dot separated, e.g. 11000000.10101000.00000001.00000001): ";
        cin >> s;
        // split the four octets on the dots
        string oct;
        bool first = true;
        for(int i=0; i<=(int)s.size(); i++){
            if(i==(int)s.size() || s[i]=='.'){
                if(!first) cout << ".";
                cout << stoi(oct, nullptr, 2);
                oct.clear();
                first = false;
            } else oct += s[i];
        }
        cout << "\n";
    }
    else cout << "invalid choice\n";

    return 0;
}
