// tcp 3-way handshake and FIN teardown - just the control exchange with seq/ack numbers
#include<iostream>
using namespace std;

int main()
{
    unsigned x = 1000;     // client initial sequence number
    unsigned y = 5000;     // server initial sequence number

    cout << "-- setup (3-way handshake) --\n";
    cout << "client -> server  SYN      seq=" << x << "\n";
    cout << "server -> client  SYN,ACK  seq=" << y << " ack=" << x+1 << "\n";
    cout << "client -> server  ACK      seq=" << x+1 << " ack=" << y+1 << "\n";
    cout << "  connection established\n\n";

    unsigned cseq = x + 1;
    unsigned sseq = y + 1;
    int len = 20;          // client sends 20 bytes

    cout << "-- data --\n";
    cout << "client -> server  PSH,ACK  seq=" << cseq << " ack=" << sseq << " len=" << len << "\n";
    cout << "server -> client  ACK      seq=" << sseq << " ack=" << cseq + len << "\n\n";
    cseq += len;

    cout << "-- teardown (FIN) --\n";
    cout << "client -> server  FIN,ACK  seq=" << cseq << " ack=" << sseq << "\n";
    cout << "server -> client  ACK      seq=" << sseq << " ack=" << cseq+1 << "\n";
    cout << "server -> client  FIN,ACK  seq=" << sseq << " ack=" << cseq+1 << "\n";
    cout << "client -> server  ACK      seq=" << cseq+1 << " ack=" << sseq+1 << "\n";
    cout << "  connection closed\n";
    return 0;
}
