/* Bindu Bhargava  19-09-19 */
// lab 11 - TCP client and server in one program, pick the role from argv
// run  ./a server  in one terminal and  ./a client  in another. the client
// sends a line, the server echoes it back. loopback only, port 9201.
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9201

int server()
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

    // ::bind not bind - std::bind clashes because of using namespace std
    if(::bind(srv, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("bind"); return 1; }
    listen(srv, 5);
    cout << "server listening on " << PORT << "\n";

    int fd = accept(srv, NULL, NULL);
    if(fd < 0){ perror("accept"); return 1; }

    char buf[1024] = {0};
    ssize_t n = recv(fd, buf, sizeof(buf) - 1, 0);
    if(n > 0){
        buf[n] = '\0';
        cout << "got: " << buf << "\n";
        send(fd, buf, n, 0);          // echo it straight back
    }
    close(fd);
    close(srv);
    return 0;
}

int client()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    if(connect(s, (sockaddr*)&srv, sizeof(srv)) < 0){ perror("connect"); return 1; }

    const char *msg = "hello over tcp";
    send(s, msg, strlen(msg), 0);

    char buf[1024] = {0};
    ssize_t n = recv(s, buf, sizeof(buf) - 1, 0);
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
