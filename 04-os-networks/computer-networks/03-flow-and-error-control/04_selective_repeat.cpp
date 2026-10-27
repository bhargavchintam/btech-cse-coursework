// selective repeat ARQ - individual ACK/NAK, receiver buffers out-of-order
// frames, sender retransmits ONLY the frame that was lost
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int total = 7;                  // frames 0..6
    int N = 4;                      // window size
    int lost = 2;                   // frame 2 lost, first time only
    bool lostActive = true;

    vector<bool> ackd(total, false);    // sender: frame acknowledged
    vector<bool> recvd(total, false);   // receiver: frame in hand (maybe buffered)
    int base = 0;                       // window base = lowest unacked
    int rexp = 0;                       // receiver's next frame to deliver
    int maxSent = -1;

    cout << "selective repeat, " << total << " frames, window size " << N << "\n\n";

    while(base < total){
        int end = min(base + N, total);
        cout << "window [" << base << ".." << end-1 << "]\n";

        int missing = -1;
        for(int f = base; f < end; f++){
            if(ackd[f]) continue;               // already acked - do NOT resend it

            bool re = (f <= maxSent);
            cout << "sender   -> frame " << f << (re ? "   [retransmit]" : "");

            if(f == lost && lostActive){
                cout << "   ...lost in transit\n";
                lostActive = false;
                missing = f;
                if(f > maxSent) maxSent = f;
                continue;                       // no ACK comes back, stays unacked
            }
            cout << "\n";
            if(f > maxSent) maxSent = f;
            recvd[f] = true;

            if(f == rexp){
                cout << "receiver <- frame " << f << " ok, ACK " << f << "\n";
                while(rexp < total && recvd[rexp]) rexp++;   // deliver the contiguous run
            } else {
                cout << "receiver <- frame " << f << " buffered, ACK " << f
                     << ", NAK " << rexp << "\n";
            }
            ackd[f] = true;
        }

        while(base < total && ackd[base]) base++;
        if(base >= total){ cout << "\n"; break; }

        if(missing != -1)
            cout << "sender   -- NAK " << missing << ", resend only frame " << missing << "\n\n";
        else
            cout << "sender   -- slide window to " << base << "\n\n";
    }

    cout << "all " << total << " frames delivered in order\n";
    return 0;
}
