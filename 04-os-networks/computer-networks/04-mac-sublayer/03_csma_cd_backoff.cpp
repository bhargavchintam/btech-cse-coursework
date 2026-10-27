// CSMA/CD binary exponential backoff - after k collisions wait a random slot in [0, 2^k - 1]
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));

    int maxColl = 6;
    cout << "how many collisions to simulate (1-16)? ";
    cin >> maxColl;
    if(maxColl < 1) maxColl = 1;
    if(maxColl > 16) maxColl = 16;

    cout << "\ncollision  k   range [0, 2^k-1]   picked slot\n";
    cout << "-------------------------------------------------\n";

    for(int c = 1; c <= maxColl; c++){
        int k = (c > 10) ? 10 : c;      // exponent capped at 10
        int range = (1 << k);            // 2^k
        int slot = rand() % range;       // random wait in [0, 2^k - 1]
        cout << "   " << c << "        " << k
             << "   [0, " << range-1 << "]"
             << "\t   " << slot << "\n";
    }

    if(maxColl >= 16)
        cout << "\n16 collisions reached - frame is dropped, give up\n";
    return 0;
}
