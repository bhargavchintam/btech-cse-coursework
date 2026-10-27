// daytime server - sends the current date and time to whoever connects
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9106

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
    cout << "daytime server on port " << PORT << "\n";

    while(true){
        int fd = accept(srv, NULL, NULL);
        if(fd < 0){ perror("accept"); continue; }

        time_t t = time(NULL);
        char *ts = ctime(&t);       // ctime string already ends in a newline
        send(fd, ts, strlen(ts), 0);
        close(fd);
    }

    close(srv);
    return 0;
}
