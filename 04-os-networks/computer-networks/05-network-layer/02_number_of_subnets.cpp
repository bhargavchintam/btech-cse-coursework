// number of subnets - borrow some host bits, list the subnets you get and hosts in each
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

int main()
{
    cout << "base network, old prefix, bits to borrow (e.g. 192.168.1.0 24 3): ";
    string ipstr;
    int oldp, borrow;
    cin >> ipstr >> oldp >> borrow;

    int newp = oldp + borrow;
    if(newp > 30){ cout << "not enough host bits left\n"; return 1; }

    uint32_t base = parseip(ipstr) & (0xFFFFFFFFu << (32 - oldp));
    int subnets = 1 << borrow;
    uint32_t block = 1u << (32 - newp);       // addresses per subnet
    int hosts = block - 2;

    cout << "new prefix     /" << newp << "\n";
    cout << "subnets        " << subnets << "\n";
    cout << "hosts / subnet " << hosts << "\n\n";
    cout << "subnet         network        broadcast\n";
    for(int i = 0; i < subnets; i++){
        uint32_t net = base + (uint32_t)i * block;
        cout << i << "              " << tostr(net) << "    " << tostr(net + block - 1) << "\n";
    }
    return 0;
}
