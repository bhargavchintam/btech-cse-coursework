// chat client - select on stdin + socket, type lines to send, print whatever the server pushes
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/select.h>
using namespace std;

#define PORT 9301

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

    fd_set set;
    char buf[1024];
    while(true){
        FD_ZERO(&set);
        FD_SET(0, &set);          // stdin
        FD_SET(s, &set);

        if(select(s+1, &set, NULL, NULL, NULL) < 0){ perror("select"); break; }

        if(FD_ISSET(s, &set)){
            ssize_t n = recv(s, buf, sizeof(buf)-1, 0);
            if(n <= 0){ cout << "server closed\n"; break; }
            buf[n] = '\0';
            cout << buf;
            cout.flush();
        }

        if(FD_ISSET(0, &set)){
            ssize_t n = read(0, buf, sizeof(buf));    // read the fd directly, dont mix stdio with select
            if(n <= 0) break;                         // ctrl-D
            send(s, buf, n, 0);
        }
    }

    close(s);
    return 0;
}
