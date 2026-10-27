// file transfer server - reads a "size name\n" header then that many bytes and saves the file
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9302

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
    listen(srv, 1);
    cout << "ft server on port " << PORT << ", waiting for a file\n";

    int fd = accept(srv, NULL, NULL);
    if(fd < 0){ perror("accept"); return 1; }

    // header is one line: the size, a space, then the filename. read up to the newline
    string header;
    char c;
    while(recv(fd, &c, 1, 0) == 1){
        if(c == '\n') break;
        header += c;
    }

    size_t sp = header.find(' ');
    if(sp == string::npos){ cout << "bad header\n"; close(fd); return 1; }
    long size = atol(header.substr(0, sp).c_str());
    string name = "recv_" + header.substr(sp+1);    // prefix so we dont clobber the original

    ofstream out(name.c_str(), ios::binary);
    if(!out){ cout << "cannot write " << name << "\n"; close(fd); return 1; }

    char buf[4096];
    long left = size;
    while(left > 0){
        ssize_t want = (left < (long)sizeof(buf)) ? left : (long)sizeof(buf);
        ssize_t n = recv(fd, buf, want, 0);        // recv can hand back less than asked, so loop
        if(n <= 0) break;
        out.write(buf, n);
        left -= n;
    }

    cout << "got " << (size - left) << " of " << size << " bytes -> " << name << "\n";
    out.close();
    close(fd);
    close(srv);
    return 0;
}
