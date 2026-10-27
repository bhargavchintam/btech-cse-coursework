// transport demultiplexing - hand each incoming segment to the process bound to its port
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<int,string> ports;
    ports[80] = "httpd";
    ports[22] = "sshd";
    ports[53] = "named";
    ports[25] = "smtpd";

    struct Seg { int port; string data; };
    Seg in[] = {
        {80,   "GET /index.html"},
        {22,   "SSH-2.0 handshake"},
        {53,   "query for example.com"},
        {8080, "some request"},
        {25,   "MAIL FROM:<a@b.com>"},
    };
    int n = sizeof(in)/sizeof(in[0]);

    for(int i = 0; i < n; i++){
        cout << "segment -> port " << in[i].port << " : ";
        if(ports.count(in[i].port))
            cout << "deliver to " << ports[in[i].port] << " (" << in[i].data << ")\n";
        else
            cout << "no process bound, dropped\n";
    }
    return 0;
}
