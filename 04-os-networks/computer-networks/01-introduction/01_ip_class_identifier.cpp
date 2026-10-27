// reads a dotted IPv4 and tells you the class, default mask and private/public
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a, b, c, d;
    cout << "enter IPv4 (a.b.c.d): ";
    if(scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4){
        cout << "bad input\n";
        return 1;
    }
    if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255){
        cout << "octet out of range\n";
        return 1;
    }

    char cls;
    const char *mask;
    if(a < 128){ cls='A'; mask="255.0.0.0 (/8)"; }
    else if(a < 192){ cls='B'; mask="255.255.0.0 (/16)"; }
    else if(a < 224){ cls='C'; mask="255.255.255.0 (/24)"; }
    else if(a < 240){ cls='D'; mask="none - multicast"; }
    else { cls='E'; mask="none - experimental"; }

    cout << "class " << cls << "\n";
    cout << "default mask: " << mask << "\n";

    // the reserved private ranges - 10/8, 172.16-31/12, 192.168/16
    bool priv = (a==10) ||
                (a==172 && b>=16 && b<=31) ||
                (a==192 && b==168) ||
                (a==127);
    if(a==127)
        cout << "loopback (127.0.0.0/8)\n";
    else if(cls=='A'||cls=='B'||cls=='C')
        cout << (priv ? "private address\n" : "public address\n");

    return 0;
}
