// tcp server - waits for a client, prints its message and replies
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
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    if(srv < 0){ perror("socket"); return 1; }

    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);        // htons - host to network byte order

    if(::bind(srv, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("bind"); return 1; }
    listen(srv, 5);
    cout << "server listening on port " << PORT << "\n";

    sockaddr_in cli;
    socklen_t len = sizeof(cli);
    int fd = accept(srv, (sockaddr*)&cli, &len);
    if(fd < 0){ perror("accept"); return 1; }
    cout << "client connected from " << inet_ntoa(cli.sin_addr) << "\n";

    char buf[1024] = {0};
    ssize_t n = recv(fd, buf, sizeof(buf)-1, 0);
    if(n > 0){
        buf[n] = '\0';
        cout << "got: " << buf << "\n";
    }

    const char *reply = "message received";
    send(fd, reply, strlen(reply), 0);

    close(fd);
    close(srv);
    return 0;
}
