// tcp echo server - sends back whatever the client sends
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9103

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
    addr.sin_port = htons(PORT);

    if(::bind(srv, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("bind"); return 1; }
    listen(srv, 5);
    cout << "echo server on port " << PORT << "\n";

    while(true){
        int fd = accept(srv, NULL, NULL);
        if(fd < 0){ perror("accept"); continue; }

        char buf[1024];
        ssize_t n;
        while((n = recv(fd, buf, sizeof(buf), 0)) > 0)
            send(fd, buf, n, 0);

        close(fd);
    }

    close(srv);
    return 0;
}
