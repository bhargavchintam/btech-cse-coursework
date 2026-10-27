// lab 8 - stop and wait ARQ
// the sender sends one frame and blocks until its ack comes back before sending
// the next one. if the ack does not arrive in time (frame or ack lost) it times
// out and resends the same frame. loss here is faked with a random draw.
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int n;
    cout << "number of frames: ";
    cin >> n;
    srand(time(0));

    for(int i = 1; i <= n; i++){
        while(true){
            cout << "sending frame " << i << "\n";
            if(rand() % 4 == 0){                 // roughly one in four goes missing
                cout << "   timeout, no ack for " << i << " - resend\n";
            } else {
                cout << "   ack " << i << " received\n";
                break;
            }
        }
    }
    cout << "all frames delivered\n";
    return 0;
}
