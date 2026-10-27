// lab 12 - UDP client and server in one program, role from argv
// run  ./a server  and then  ./a client . udp is connectionless so the client
// just sends a datagram with sendto and the server replies with sendto to the
// address it got from recvfrom. loopback only, port 9202.
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9202

int server()
{
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    int opt = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if(::bind(s, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("bind"); return 1; }
    cout << "udp server on " << PORT << "\n";

    sockaddr_in cli;
    socklen_t len = sizeof(cli);
    char buf[1024] = {0};
    ssize_t n = recvfrom(s, buf, sizeof(buf) - 1, 0, (sockaddr*)&cli, &len);
    if(n > 0){
        buf[n] = '\0';
        cout << "got: " << buf << "\n";
        sendto(s, buf, n, 0, (sockaddr*)&cli, len);
    }
    close(s);
    return 0;
}

int client()
{
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    const char *msg = "hello over udp";
    sendto(s, msg, strlen(msg), 0, (sockaddr*)&srv, sizeof(srv));

    char buf[1024] = {0};
    socklen_t len = sizeof(srv);
    ssize_t n = recvfrom(s, buf, sizeof(buf) - 1, 0, (sockaddr*)&srv, &len);
    if(n > 0){ buf[n] = '\0'; cout << "server echoed: " << buf << "\n"; }

    close(s);
    return 0;
}

int main(int argc, char **argv)
{
    if(argc < 2){ cout << "usage: " << argv[0] << " server|client\n"; return 1; }
    string mode = argv[1];
    if(mode == "server") return server();
    if(mode == "client") return client();
    cout << "unknown mode " << mode << "\n";
    return 1;
}
