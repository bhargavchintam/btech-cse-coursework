// sliding window - watch the sender and receiver windows slide as frames
// go out and ACKs come back. no loss here, just the window movement
#include<iostream>
#include<algorithm>
using namespace std;

void win(const char* who, int lo, int total){
    int hi = min(lo + 4 - 1, total - 1);       // window size 4
    if(lo >= total){ cout << "  " << who << " window = [ -- ]\n"; return; }
    cout << "  " << who << " window = [" << lo << ".." << hi << "]\n";
}

int main()
{
    int total = 8;                  // frames 0..7
    int W = 4;

    int sbase = 0;                  // oldest unacked frame (sender)
    int nextseq = 0;                // next frame to send
    int rexp = 0;                   // frame the receiver is expecting

    cout << "sliding window, " << total << " frames, window size " << W << "\n\n";

    while(sbase < total){
        while(nextseq < sbase + W && nextseq < total){
            cout << "sender   -> frame " << nextseq << "\n";
            nextseq++;
        }
        win("sender  ", sbase, total);

        // receiver takes the next in-order frame and acks it
        cout << "receiver <- frame " << rexp << ", ACK " << rexp + 1 << "\n";
        rexp++;
        win("receiver", rexp, total);

        sbase++;
        cout << "  ACK " << sbase << " in -> sender window slides\n";
        win("sender  ", sbase, total);
        cout << "\n";
    }

    cout << "window emptied, all " << total << " frames sent and acked\n";
    return 0;
}
