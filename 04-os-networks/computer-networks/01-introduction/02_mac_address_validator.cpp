// validate a MAC address like aa:bb:cc:dd:ee:ff and split OUI from NIC part
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool hexdig(char c){ return isdigit((unsigned char)c) || (tolower(c)>='a' && tolower(c)<='f'); }

int main()
{
    string s;
    cout << "enter MAC: ";
    cin >> s;

    // must be 17 chars: 6 groups of 2 hex with 5 colons
    bool ok = (s.size() == 17);
    for(int i=0; ok && i<(int)s.size(); i++){
        if((i+1)%3 == 0){
            if(s[i] != ':') ok = false;      // every 3rd char is a colon
        } else {
            if(!hexdig(s[i])) ok = false;
        }
    }

    if(!ok){
        cout << "invalid MAC address\n";
        return 1;
    }

    cout << "valid MAC address\n";
    // first 3 bytes = OUI (the vendor), last 3 = NIC (the card)
    cout << "OUI (vendor): " << s.substr(0,8) << "\n";
    cout << "NIC (device): " << s.substr(9) << "\n";

    // the low bit of the first byte says unicast vs multicast
    int first = stoi(s.substr(0,2), nullptr, 16);
    cout << (first & 1 ? "multicast" : "unicast") << ", ";
    cout << (first & 2 ? "locally administered" : "globally unique") << "\n";
    return 0;
}
