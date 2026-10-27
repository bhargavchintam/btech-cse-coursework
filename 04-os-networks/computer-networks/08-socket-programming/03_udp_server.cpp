// udp server - recvfrom a client and reply with sendto
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9102

int main()
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
    cout << "udp server up on port " << PORT << "\n";

    sockaddr_in cli;
    socklen_t len = sizeof(cli);
    char buf[1024] = {0};

    // no accept for udp, recvfrom hands back the sender address
    ssize_t n = recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr*)&cli, &len);
    if(n > 0){
        buf[n] = '\0';
        cout << "got: " << buf << " from " << inet_ntoa(cli.sin_addr) << "\n";
    }

    const char *reply = "ack from udp server";
    sendto(s, reply, strlen(reply), 0, (sockaddr*)&cli, len);

    close(s);
    return 0;
}
