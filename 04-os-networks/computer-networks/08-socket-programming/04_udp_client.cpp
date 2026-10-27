// udp client - sendto the server then recvfrom the reply
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

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    const char *msg = "hello over udp";
    sendto(s, msg, strlen(msg), 0, (sockaddr*)&srv, sizeof(srv));

    char buf[1024] = {0};
    sockaddr_in from;
    socklen_t len = sizeof(from);
    ssize_t n = recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr*)&from, &len);
    if(n > 0){
        buf[n] = '\0';
        cout << "server says: " << buf << "\n";
    }

    close(s);
    return 0;
}
