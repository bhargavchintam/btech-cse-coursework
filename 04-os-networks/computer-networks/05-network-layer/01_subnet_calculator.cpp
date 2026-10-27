// subnet calculator - from an ip and a mask (/n or dotted) work out the network details
#include<iostream>
#include<string>
#include<cstdint>
using namespace std;

uint32_t parseip(const string &s)
{
    uint32_t a, b, c, d;
    sscanf(s.c_str(), "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

string tostr(uint32_t x)
{
    char t[20];
    snprintf(t, sizeof(t), "%u.%u.%u.%u", (x >> 24) & 0xFF, (x >> 16) & 0xFF, (x >> 8) & 0xFF, x & 0xFF);
    return string(t);
}

int prefixof(uint32_t mask)
{
    int p = 0;
    for(int i = 31; i >= 0; i--){
        if((mask >> i) & 1) p++;
        else break;
    }
    return p;
}

int main()
{
    cout << "ip and mask (e.g. 192.168.1.10 /26  or  192.168.1.10 255.255.255.192): ";
    string ipstr, mstr;
    cin >> ipstr >> mstr;

    uint32_t ip = parseip(ipstr);
    int prefix;
    uint32_t mask;

    if(mstr.find('.') != string::npos){       // dotted mask
        mask = parseip(mstr);
        prefix = prefixof(mask);
    } else {                                   // /n or plain n
        if(mstr[0] == '/') mstr = mstr.substr(1);
        prefix = stoi(mstr);
        mask = (prefix == 0) ? 0u : (0xFFFFFFFFu << (32 - prefix));
    }

    uint32_t net = ip & mask;
    uint32_t bcast = net | ~mask;

    cout << "address    " << tostr(ip) << "/" << prefix << "\n";
    cout << "mask       " << tostr(mask) << "\n";
    cout << "network    " << tostr(net) << "\n";
    cout << "broadcast  " << tostr(bcast) << "\n";

    if(prefix <= 30){
        cout << "first host " << tostr(net + 1) << "\n";
        cout << "last host  " << tostr(bcast - 1) << "\n";
        cout << "usable hosts " << ((1u << (32 - prefix)) - 2) << "\n";
    } else {
        cout << "too small for usable host range at /" << prefix << "\n";
    }
    return 0;
}
