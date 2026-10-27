// token passing among n stations - the token goes round, one station sends when it holds it
#include<iostream>
using namespace std;

int main()
{
    int n, sender, dest, rounds;
    cout << "number of stations: ";
    cin >> n;
    if(n < 2){ cout << "need at least 2 stations\n"; return 1; }

    cout << "which station wants to send (0.." << n-1 << ")? ";
    cin >> sender;
    cout << "destination station? ";
    cin >> dest;
    cout << "how many hops to show? ";
    cin >> rounds;

    if(sender < 0 || sender >= n || dest < 0 || dest >= n){
        cout << "station out of range\n";
        return 1;
    }

    int tok = 0;    // token starts at station 0
    for(int i = 0; i < rounds; i++){
        cout << "token at station " << tok;
        if(tok == sender){
            cout << "  -> has data, sends frame to station " << dest << "\n";
            // frame rides the ring until it reaches the destination
            int p = tok;
            while(p != dest){
                p = (p + 1) % n;
                cout << "    frame passing station " << p << "\n";
            }
            cout << "    station " << dest << " copies the frame\n";
        } else {
            cout << "  -> nothing to send, passes token on\n";
        }
        tok = (tok + 1) % n;    // token moves to the next station
    }
    return 0;
}
