// go-back-N ARQ - window of N, cumulative ACK, one loss makes the sender
// go back and resend that frame and everything after it
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int total = 7;                  // frames 0..6
    int N = 4;                      // window size
    int lost = 2;                   // frame 2 is lost, but only the first time
    bool lostActive = true;

    int base = 0;                   // oldest unacked frame
    int maxSent = -1;               // highest frame index ever put on the wire

    cout << "go-back-N, " << total << " frames, window size " << N << "\n\n";

    while(base < total){
        int end = min(base + N, total);
        cout << "window [" << base << ".." << end-1 << "]\n";

        int expected = base;        // next in-order frame the receiver wants
        bool discarding = false;    // once a gap appears, drop the rest of the window
        bool roundLoss = false;

        for(int f = base; f < end; f++){
            bool re = (f <= maxSent);
            cout << "sender   -> frame " << f << (re ? "   [retransmit]" : "");

            if(f == lost && lostActive){
                cout << "   ...lost in transit\n";
                lostActive = false;
                discarding = true;
                roundLoss = true;
                if(f > maxSent) maxSent = f;
                continue;
            }
            cout << "\n";
            if(f > maxSent) maxSent = f;

            if(discarding)
                cout << "receiver <- frame " << f << " out of order (expected "
                     << expected << "), discard, ACK " << expected << "\n";
            else{
                expected = f + 1;
                cout << "receiver <- frame " << f << " ok, ACK " << expected << "\n";
            }
        }

        base = expected;
        if(base >= total){ cout << "\n"; break; }

        if(roundLoss)
            cout << "sender   -- timeout on frame " << base << ", go back to " << base << "\n\n";
        else
            cout << "sender   -- acked through " << base << ", slide window\n\n";
    }

    cout << "all " << total << " frames delivered\n";
    return 0;
}
