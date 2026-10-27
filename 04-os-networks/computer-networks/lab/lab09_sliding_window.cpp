// lab 9 - sliding window, go back N
// the sender can have up to W frames outstanding without an ack. if a frame is
// lost the receiver drops it and everything after it, so the sender goes back to
// that frame and resends the whole window from there.
#include<iostream>
using namespace std;

int main()
{
    int n, w, lost;
    cout << "total frames: ";
    cin >> n;
    cout << "window size: ";
    cin >> w;
    cout << "which frame gets lost once: ";
    cin >> lost;

    int base = 1;
    bool dropped = false;
    while(base <= n){
        int end = (base + w - 1 < n) ? base + w - 1 : n;
        cout << "sending frames " << base << " to " << end << "\n";
        if(!dropped && lost >= base && lost <= end){
            cout << "   frame " << lost << " lost, ack only up to " << lost - 1 << "\n";
            cout << "   go back to " << lost << "\n";
            dropped = true;
            base = lost;
        } else {
            cout << "   acks up to " << end << "\n";
            base = end + 1;
        }
    }
    cout << "transfer complete\n";
    return 0;
}
