// file receiver - connects to the sender and writes the incoming bytes to a file
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9107

int main(int argc, char *argv[])
{
    const char *out = (argc > 1) ? argv[1] : "received.dat";

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    if(connect(s, (sockaddr*)&srv, sizeof(srv)) < 0){ perror("connect"); return 1; }

    ofstream f(out, ios::binary);
    if(!f){ cout << "cannot write " << out << "\n"; return 1; }

    char buf[4096];
    long total = 0;
    ssize_t n;
    while((n = recv(s, buf, sizeof(buf), 0)) > 0){
        f.write(buf, n);
        total += n;
    }

    cout << "received " << total << " bytes into " << out << "\n";
    f.close();
    close(s);
    return 0;
}
