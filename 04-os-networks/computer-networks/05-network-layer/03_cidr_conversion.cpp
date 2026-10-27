// cidr conversion - /n prefix to a dotted mask and back, whichever you type
#include<iostream>
#include<string>
#include<cstdint>
using namespace std;

string tostr(uint32_t x)
{
    char t[20];
    snprintf(t, sizeof(t), "%u.%u.%u.%u", (x >> 24) & 0xFF, (x >> 16) & 0xFF, (x >> 8) & 0xFF, x & 0xFF);
    return string(t);
}

int main()
{
    cout << "enter /n prefix or a dotted mask (e.g. /26  or  255.255.255.192): ";
    string in;
    cin >> in;

    if(in.find('.') != string::npos){
        uint32_t a, b, c, d;
        sscanf(in.c_str(), "%u.%u.%u.%u", &a, &b, &c, &d);
        uint32_t mask = (a << 24) | (b << 16) | (c << 8) | d;
        int p = 0;
        for(int i = 31; i >= 0; i--){
            if((mask >> i) & 1) p++;
            else break;
        }
        cout << in << "  ->  /" << p << "\n";
    } else {
        if(in[0] == '/') in = in.substr(1);
        int p = stoi(in);
        uint32_t mask = (p == 0) ? 0u : (0xFFFFFFFFu << (32 - p));
        cout << "/" << p << "  ->  " << tostr(mask) << "\n";
    }
    return 0;
}
