// routing table lookup - longest prefix match of a destination ip against the table
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

struct Route { const char *net; int prefix; const char *gw; };

Route table[] = {
    { "0.0.0.0",         0,  "10.0.0.1" },     // default route
    { "192.168.0.0",     16, "10.0.0.2" },
    { "192.168.1.0",     24, "10.0.0.3" },
    { "192.168.1.128",   25, "10.0.0.4" },
};
int nroutes = sizeof(table) / sizeof(table[0]);

int main()
{
    cout << "destination ip(s), one per line:\n";
    string ipstr;
    while(cin >> ipstr){
        uint32_t dst = parseip(ipstr);
        int best = -1, bestlen = -1;

        for(int i = 0; i < nroutes; i++){
            uint32_t mask = (table[i].prefix == 0) ? 0u : (0xFFFFFFFFu << (32 - table[i].prefix));
            if((dst & mask) == parseip(table[i].net) && table[i].prefix > bestlen){
                bestlen = table[i].prefix;
                best = i;
            }
        }

        cout << ipstr << "  ->  " << table[best].net << "/" << table[best].prefix
             << " via " << table[best].gw << "\n";
    }
    return 0;
}
