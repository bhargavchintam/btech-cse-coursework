// file transfer client - sends "size name\n" then streams the file bytes in chunks
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9302

int main(int argc, char *argv[])
{
    if(argc < 2){ cout << "usage: " << argv[0] << " <file-to-send>\n"; return 1; }

    ifstream in(argv[1], ios::binary);
    if(!in){ cout << "cannot open " << argv[1] << "\n"; return 1; }

    in.seekg(0, ios::end);
    long size = in.tellg();
    in.seekg(0, ios::beg);

    string path = argv[1];
    size_t slash = path.find_last_of('/');
    string name = (slash == string::npos) ? path : path.substr(slash+1);   // drop the dir part

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){ perror("socket"); return 1; }

    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    if(connect(s, (sockaddr*)&srv, sizeof(srv)) < 0){ perror("connect"); return 1; }

    string header = to_string(size) + " " + name + "\n";
    send(s, header.c_str(), header.size(), 0);

    char buf[4096];
    long total = 0;
    while(in){
        in.read(buf, sizeof(buf));
        streamsize got = in.gcount();
        if(got <= 0) break;

        char *p = buf;
        streamsize l = got;
        while(l > 0){                       // send() may not push it all in one go
            ssize_t sent = send(s, p, l, 0);
            if(sent <= 0){ perror("send"); break; }
            p += sent;
            l -= sent;
        }
        total += got;
    }

    cout << "sent " << total << " bytes (" << name << ")\n";
    in.close();
    close(s);
    return 0;
}
