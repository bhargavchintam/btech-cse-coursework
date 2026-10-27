/* Bindu Bhargava   28-08-19 */
// tcp congestion window - slow start (exponential) then congestion avoidance (linear),
// a loss halves cwnd and resets the threshold
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int cwnd = 1;          // measured in MSS
    int ssthresh = 16;
    int rtts = 16;
    int drop_at = 10;      // loss gets detected at this RTT

    printf("start: cwnd=1  ssthresh=%d\n\n", ssthresh);
    printf("rtt  cwnd  ssthresh  phase\n");

    for(int r = 1; r <= rtts; r++){
        const char *phase = (cwnd < ssthresh) ? "slow start" : "congestion avoid";
        printf("%3d  %4d  %8d  %s\n", r, cwnd, ssthresh, phase);

        if(r == drop_at){
            ssthresh = cwnd / 2;
            cwnd = ssthresh;                 // fast recovery, cut the window in half
            printf("       -- loss! ssthresh=%d, cwnd=%d --\n", ssthresh, cwnd);
            continue;
        }

        if(cwnd < ssthresh)
            cwnd *= 2;                       // double each RTT
        else
            cwnd += 1;                       // grow by one each RTT
    }
    return 0;
}
