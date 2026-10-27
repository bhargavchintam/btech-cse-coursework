// token bucket - tokens refill each tick, a packet needs one token to go out (bursts allowed)
#include<iostream>
#include<cstdio>
using namespace std;

#define CAP 6
#define RATE 2

int main()
{
    int arr[] = {0, 5, 1, 0, 7, 2, 0, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tokens = CAP;      // start with a full bucket
    int queue = 0;

    printf("token cap=%d  refill=%d per tick\n\n", CAP, RATE);
    printf("tick  arrive  tokens  sent  queue\n");

    int t = 0;
    while(t < n || queue > 0){
        tokens += RATE;
        if(tokens > CAP) tokens = CAP;

        int in = (t < n) ? arr[t] : 0;
        queue += in;

        int sent = (queue < tokens) ? queue : tokens;
        queue -= sent;
        tokens -= sent;

        printf("%3d  %6d  %6d  %4d  %5d\n", t+1, in, tokens, sent, queue);
        t++;
    }
    return 0;
}
