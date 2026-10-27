// dhcp DORA - discover / offer / request / ack, server leases the client an address
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string cli_mac = "00:1a:2b:3c:4d:5e";
    string offered = "192.168.1.50";
    string server  = "192.168.1.1";
    string mask    = "255.255.255.0";
    string gw      = "192.168.1.1";
    string dns     = "192.168.1.1";
    int lease = 86400;     // seconds (24 hours)

    cout << "client MAC " << cli_mac << ", no IP yet (0.0.0.0)\n\n";

    cout << "1. DISCOVER  client -> broadcast 255.255.255.255\n";
    cout << "   \"anyone got an address for me?\"  xid=0x3903f326\n\n";

    cout << "2. OFFER     server " << server << " -> client\n";
    cout << "   offering " << offered << "  mask " << mask << "  lease " << lease << "s\n\n";

    cout << "3. REQUEST   client -> broadcast\n";
    cout << "   \"I'll take " << offered << " from " << server << "\"\n\n";

    cout << "4. ACK       server " << server << " -> client\n";
    cout << "   " << offered << " is yours for " << lease << "s\n\n";

    cout << "lease bound:\n";
    cout << "  ip      " << offered << "\n";
    cout << "  mask    " << mask << "\n";
    cout << "  gateway " << gw << "\n";
    cout << "  dns     " << dns << "\n";
    cout << "  renew T1 at " << lease/2 << "s, rebind T2 at " << lease*7/8 << "s\n";
    return 0;
}
