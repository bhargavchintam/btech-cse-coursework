/* Bindu Bhargava   17-10-19 */
// concurrent tcp server - forks a child to handle each client
#include<iostream>
#include<cstring>
#include<cstdio>
#include<csignal>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9104

int main()
{
    signal(SIGCHLD, SIG_IGN);       // let the kernel reap dead children, no zombies

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
    cout << "concurrent server on port " << PORT << "\n";

    while(true){
        sockaddr_in cli;
        socklen_t len = sizeof(cli);
        int fd = accept(srv, (sockaddr*)&cli, &len);
        if(fd < 0){ perror("accept"); continue; }

        if(fork() == 0){
            close(srv);             // child does not need the listener
            char buf[1024] = {0};
            ssize_t n = recv(fd, buf, sizeof(buf)-1, 0);
            if(n > 0){
                buf[n] = '\0';
                cout << "[child " << getpid() << "] got: " << buf << "\n";
            }
            char reply[128];
            snprintf(reply, sizeof(reply), "handled by child %d", getpid());
            send(fd, reply, strlen(reply), 0);
            close(fd);
            _exit(0);
        }
        close(fd);                  // parent is done with this one
    }
    return 0;
}
