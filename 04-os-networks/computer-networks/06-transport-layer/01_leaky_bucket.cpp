// leaky bucket - smooth a bursty input into a fixed output rate, overflow is dropped
#include<iostream>
#include<cstdio>
using namespace std;

#define CAP 10
#define RATE 3

int main()
{
    int arr[] = {4, 8, 2, 0, 6, 5, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int bucket = 0;

    printf("bucket cap=%d  leak=%d per tick\n\n", CAP, RATE);
    printf("tick  arrive  drop  bucket  send\n");

    int t = 0;
    while(t < n || bucket > 0){
        int in = (t < n) ? arr[t] : 0;
        int arrive = in;
        int drop = 0;
        if(bucket + in > CAP){
            drop = bucket + in - CAP;
            in -= drop;
        }
        bucket += in;
        int send = (bucket < RATE) ? bucket : RATE;
        bucket -= send;
        printf("%3d  %6d  %4d  %6d  %4d\n", t+1, arrive, drop, bucket, send);
        t++;
    }
    return 0;
}
