// transmission time, propagation delay, total delay and bandwidth-delay product
#include<iostream>
using namespace std;

int main()
{
    double bits, bw, dist, speed;
    cout << "data size (bits): ";
    cin >> bits;
    cout << "bandwidth (bits/sec): ";
    cin >> bw;
    cout << "distance (metres): ";
    cin >> dist;
    cout << "propagation speed (m/s): ";
    cin >> speed;

    if(bw <= 0 || speed <= 0){
        cout << "bandwidth and speed must be > 0\n";
        return 1;
    }

    double tt = bits / bw;          // time to push the bits out
    double pd = dist / speed;       // time for a bit to cross the link
    double total = tt + pd;
    double bdp = bw * pd;           // bits in flight

    cout << "\ntransmission time = " << tt << " s\n";
    cout << "propagation delay = " << pd << " s\n";
    cout << "total delay       = " << total << " s\n";
    cout << "bandwidth-delay product = " << bdp << " bits\n";
    return 0;
}
