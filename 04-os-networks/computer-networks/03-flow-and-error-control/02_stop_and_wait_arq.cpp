/* Bindu Bhargava   09-09-19 */
// stop-and-wait ARQ - timer + retransmit on a lost frame and a lost ACK
#include<iostream>
using namespace std;

// frame 2 gets lost on its first try, and the ACK for frame 3 gets lost
bool frame_lost(int i, int attempt){ return i == 2 && attempt == 1; }
bool ack_lost(int i, int attempt){ return i == 3 && attempt == 1; }

int main()
{
    int frames = 5;
    int seq = 0;

    cout << "stop-and-wait ARQ, " << frames << " frames\n\n";

    for(int i = 0; i < frames; i++){
        int attempt = 1;
        bool delivered = false;             // did the receiver already get this frame
        while(true){
            cout << "sender   -> frame seq=" << seq << " (d" << i << ")";
            if(attempt > 1) cout << "   [retransmit]";
            cout << "\n";

            if(frame_lost(i, attempt)){
                cout << "              ...frame lost in transit\n";
                cout << "sender   -- timeout, no ACK\n\n";
                attempt++;
                continue;
            }

            if(delivered)
                cout << "receiver <- duplicate frame " << seq << ", drop it, re-send ACK " << (seq ^ 1) << "\n";
            else{
                cout << "receiver <- got frame " << seq << ", send ACK " << (seq ^ 1) << "\n";
                delivered = true;
            }

            if(ack_lost(i, attempt)){
                cout << "              ...ACK lost in transit\n";
                cout << "sender   -- timeout, resend same frame\n\n";
                attempt++;
                continue;
            }

            cout << "sender   -- ACK " << (seq ^ 1) << " received, move on\n\n";
            break;
        }
        seq ^= 1;
    }

    cout << "all frames acknowledged\n";
    return 0;
}
