// select based server - one thread juggling many clients, echoes each line back
#include<iostream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/select.h>
using namespace std;

#define PORT 9105
#define MAXCLI 30

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
    cout << "select server on port " << PORT << "\n";

    int cli[MAXCLI];
    for(int i = 0; i < MAXCLI; i++) cli[i] = -1;

    fd_set set;
    while(true){
        FD_ZERO(&set);
        FD_SET(srv, &set);
        int maxfd = srv;
        for(int i = 0; i < MAXCLI; i++){
            if(cli[i] >= 0){
                FD_SET(cli[i], &set);
                if(cli[i] > maxfd) maxfd = cli[i];
            }
        }

        if(select(maxfd+1, &set, NULL, NULL, NULL) < 0){ perror("select"); break; }

        if(FD_ISSET(srv, &set)){
            int fd = accept(srv, NULL, NULL);
            if(fd >= 0){
                int i;
                for(i = 0; i < MAXCLI; i++)
                    if(cli[i] < 0){ cli[i] = fd; break; }
                if(i == MAXCLI) close(fd);      // full, drop it
                else cout << "new client on fd " << fd << "\n";
            }
        }

        for(int i = 0; i < MAXCLI; i++){
            int fd = cli[i];
            if(fd < 0 || !FD_ISSET(fd, &set)) continue;

            char buf[1024];
            ssize_t n = recv(fd, buf, sizeof(buf), 0);
            if(n <= 0){
                close(fd);
                cli[i] = -1;
                cout << "fd " << fd << " left\n";
            } else {
                send(fd, buf, n, 0);
            }
        }
    }

    close(srv);
    return 0;
}
