// file sender - listens for a receiver and streams a file over tcp in chunks
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9107

int main(int argc, char *argv[])
{
    if(argc < 2){
        cout << "usage: " << argv[0] << " <file-to-send>\n";
        return 1;
    }

    ifstream in(argv[1], ios::binary);
    if(!in){ cout << "cannot open " << argv[1] << "\n"; return 1; }

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
    listen(srv, 1);
    cout << "sender ready on port " << PORT << ", waiting for receiver\n";

    int fd = accept(srv, NULL, NULL);
    if(fd < 0){ perror("accept"); return 1; }

    char buf[4096];
    long total = 0;
    while(in){
        in.read(buf, sizeof(buf));
        streamsize got = in.gcount();
        if(got <= 0) break;

        char *p = buf;
        streamsize left = got;
        while(left > 0){                 // send() may not push it all at once
            ssize_t sent = send(fd, p, left, 0);
            if(sent <= 0){ perror("send"); break; }
            p += sent;
            left -= sent;
        }
        total += got;
    }

    cout << "sent " << total << " bytes\n";
    in.close();
    close(fd);
    close(srv);
    return 0;
}
