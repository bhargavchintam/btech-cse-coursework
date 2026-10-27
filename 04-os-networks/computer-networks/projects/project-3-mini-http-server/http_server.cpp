// mini http server - HTTP/1.0, GET only, serves files out of the current directory
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 9303

string mime(const string &path)
{
    size_t dot = path.find_last_of('.');
    string ext = (dot == string::npos) ? "" : path.substr(dot);
    if(ext == ".html" || ext == ".htm") return "text/html";
    if(ext == ".css")  return "text/css";
    if(ext == ".js")   return "application/javascript";
    if(ext == ".txt")  return "text/plain";
    return "application/octet-stream";
}

void reply(int fd, const string &status, const string &type, const string &body)
{
    ostringstream h;
    h << "HTTP/1.0 " << status << "\r\n";
    h << "Content-Type: " << type << "\r\n";
    h << "Content-Length: " << body.size() << "\r\n";
    h << "Connection: close\r\n\r\n";
    string head = h.str();
    send(fd, head.c_str(), head.size(), 0);
    send(fd, body.c_str(), body.size(), 0);
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
    cout << "http server on http://127.0.0.1:" << PORT << "/\n";

    while(true){
        int fd = accept(srv, NULL, NULL);
        if(fd < 0){ perror("accept"); continue; }

        char buf[2048] = {0};
        ssize_t n = recv(fd, buf, sizeof(buf)-1, 0);
        if(n <= 0){ close(fd); continue; }
        buf[n] = '\0';

        // first line is the request line: GET /index.html HTTP/1.1
        string method, path, ver;
        istringstream reqline(buf);
        reqline >> method >> path >> ver;

        if(method != "GET"){
            reply(fd, "501 Not Implemented", "text/plain", "only GET is supported\n");
            close(fd);
            continue;
        }

        if(path == "/") path = "/index.html";

        if(path.find("..") != string::npos){        // dont let anyone climb out of the dir
            reply(fd, "403 Forbidden", "text/plain", "nope\n");
            close(fd);
            continue;
        }

        string file = "." + path;
        ifstream f(file.c_str(), ios::binary);
        if(!f){
            reply(fd, "404 Not Found", "text/html", "<h1>404 Not Found</h1>\n");
            cout << method << " " << path << " -> 404\n";
            close(fd);
            continue;
        }

        ostringstream ss;
        ss << f.rdbuf();
        string body = ss.str();
        reply(fd, "200 OK", mime(file), body);
        cout << method << " " << path << " -> 200 (" << body.size() << " bytes)\n";
        close(fd);
    }

    close(srv);
    return 0;
}
