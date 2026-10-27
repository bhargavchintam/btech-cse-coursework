// tcp client - connects to the server, sends a line and prints the reply
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9101

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    if(connect(s, (sockaddr*)&srv, sizeof(srv)) < 0){ perror("connect"); return 1; }

    const char *msg = "hello from client";
    send(s, msg, strlen(msg), 0);

    char buf[1024] = {0};
    ssize_t n = recv(s, buf, sizeof(buf)-1, 0);
    if(n > 0){
        buf[n] = '\0';
        cout << "server says: " << buf << "\n";
    }

    close(s);
    return 0;
}
