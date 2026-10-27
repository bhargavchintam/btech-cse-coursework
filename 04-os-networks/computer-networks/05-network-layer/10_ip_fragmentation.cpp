// ip fragmentation - split a datagram to fit an mtu, print each fragment's offset/len/MF
#include<iostream>
using namespace std;

int main()
{
    int hdr = 20;
    cout << "data size (bytes) and link mtu (e.g. 3980 1500): ";
    int data, mtu;
    cin >> data >> mtu;

    int maxdata = ((mtu - hdr) / 8) * 8;       // payload per fragment, kept a multiple of 8
    if(maxdata <= 0){ cout << "mtu too small for the header\n"; return 1; }

    if(data <= maxdata){
        cout << "fits in one datagram, no fragmentation needed\n";
        return 0;
    }

    cout << "max data per fragment " << maxdata << " bytes\n\n";
    cout << "frag  bytes  offset  MF\n";

    int off = 0, num = 1, left = data;
    while(left > 0){
        int take = (left > maxdata) ? maxdata : left;
        int mf = (left > maxdata) ? 1 : 0;
        cout << num << "     " << take << "   " << off / 8 << "     " << mf << "\n";
        off += take;
        left -= take;
        num++;
    }
    return 0;
}
