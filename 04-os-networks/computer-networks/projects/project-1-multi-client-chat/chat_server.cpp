// chat server - one select() loop, many clients, broadcasts every line to everyone else
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/select.h>
using namespace std;

#define PORT 9301
#define MAXCLI 30

struct Client {
    int fd;
    string name;
    string buf;      // bytes held back until we see a full line
};

void bcast(Client *cli, const string &line, int except)
{
    for(int j = 0; j < MAXCLI; j++)
        if(cli[j].fd >= 0 && cli[j].fd != except && !cli[j].name.empty())
            send(cli[j].fd, line.c_str(), line.size(), 0);
}

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
    cout << "chat server on port " << PORT << "\n";

    Client cli[MAXCLI];
    for(int i = 0; i < MAXCLI; i++) cli[i].fd = -1;

    fd_set set;
    while(true){
        FD_ZERO(&set);
        FD_SET(srv, &set);
        int maxfd = srv;
        for(int i = 0; i < MAXCLI; i++){
            if(cli[i].fd >= 0){
                FD_SET(cli[i].fd, &set);
                if(cli[i].fd > maxfd) maxfd = cli[i].fd;
            }
        }

        if(select(maxfd+1, &set, NULL, NULL, NULL) < 0){ perror("select"); break; }

        if(FD_ISSET(srv, &set)){
            int fd = accept(srv, NULL, NULL);
            if(fd >= 0){
                int i;
                for(i = 0; i < MAXCLI; i++)
                    if(cli[i].fd < 0){ cli[i].fd = fd; cli[i].name = ""; cli[i].buf = ""; break; }
                if(i == MAXCLI) close(fd);               // full, drop it
                else {
                    const char *p = "name: ";
                    send(fd, p, strlen(p), 0);           // first line they send is their name
                }
            }
        }

        for(int i = 0; i < MAXCLI; i++){
            int fd = cli[i].fd;
            if(fd < 0 || !FD_ISSET(fd, &set)) continue;

            char buf[1024];
            ssize_t n = recv(fd, buf, sizeof(buf), 0);
            if(n <= 0){
                if(!cli[i].name.empty()){
                    string bye = "* " + cli[i].name + " left\n";
                    cout << bye;
                    bcast(cli, bye, fd);
                }
                close(fd);
                cli[i].fd = -1;
                continue;
            }

            cli[i].buf.append(buf, n);
            size_t pos;
            while((pos = cli[i].buf.find('\n')) != string::npos){
                string line = cli[i].buf.substr(0, pos);
                cli[i].buf.erase(0, pos+1);
                if(!line.empty() && line.back() == '\r') line.pop_back();   // nc / telnet send CRLF

                if(cli[i].name.empty()){
                    cli[i].name = line.empty() ? "guest" : line;
                    string join = "* " + cli[i].name + " joined\n";
                    cout << join;
                    bcast(cli, join, fd);
                } else {
                    if(line.empty()) continue;
                    string out = cli[i].name + ": " + line + "\n";
                    cout << out;
                    bcast(cli, out, fd);
                }
            }
        }
    }

    close(srv);
    return 0;
}
