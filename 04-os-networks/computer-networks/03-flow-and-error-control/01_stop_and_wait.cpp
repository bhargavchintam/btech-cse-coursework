// stop-and-wait flow control - one frame out, wait for its ACK, then the next
#include<iostream>
using namespace std;

int main()
{
    int frames = 6;
    int seq = 0;                    // 1-bit sequence number, alternates 0/1

    cout << "stop-and-wait, " << frames << " frames\n\n";

    for(int i = 0; i < frames; i++){
        cout << "sender   -> frame seq=" << seq << " (data d" << i << ")\n";
        cout << "receiver <- got frame " << seq << ", ACK " << (seq ^ 1) << "\n";
        cout << "         sender free to send next\n\n";
        seq ^= 1;
    }

    cout << "all " << frames << " frames delivered\n";
    return 0;
}
