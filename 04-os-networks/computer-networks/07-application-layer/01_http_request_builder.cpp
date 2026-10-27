// http request builder + response parser - all in-memory strings, no real network call
#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

string build_get(const string &host, const string &path)
{
    string r;
    r += "GET " + path + " HTTP/1.1\r\n";
    r += "Host: " + host + "\r\n";
    r += "User-Agent: cn-lab/1.0\r\n";
    r += "Accept: */*\r\n";
    r += "Connection: close\r\n";
    r += "\r\n";
    return r;
}

string build_post(const string &host, const string &path, const string &body)
{
    string r;
    r += "POST " + path + " HTTP/1.1\r\n";
    r += "Host: " + host + "\r\n";
    r += "Content-Type: application/x-www-form-urlencoded\r\n";
    r += "Content-Length: " + to_string(body.size()) + "\r\n";
    r += "\r\n";
    r += body;
    return r;
}

int main()
{
    cout << "--- GET request ---\n";
    cout << build_get("example.com", "/index.html");

    cout << "\n--- POST request ---\n";
    cout << build_post("example.com", "/login", "user=bhargav&pw=secret") << "\n";

    string resp =
        "HTTP/1.1 200 OK\r\n"
        "Date: Mon, 26 Aug 2019 10:15:00 GMT\r\n"
        "Server: Apache\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 31\r\n"
        "\r\n"
        "<html><body>hello</body></html>";

    cout << "\n--- parsing a response ---\n";
    istringstream ss(resp);
    string line;
    getline(ss, line);
    if(!line.empty() && line.back() == '\r') line.pop_back();

    istringstream ls(line);
    string ver, code, reason;
    ls >> ver >> code;
    getline(ls, reason);
    while(!reason.empty() && reason.front() == ' ') reason.erase(reason.begin());
    cout << "version: " << ver << "\n";
    cout << "status : " << code << " " << reason << "\n";

    map<string,string> hdr;
    while(getline(ss, line)){
        if(!line.empty() && line.back() == '\r') line.pop_back();
        if(line.empty()) break;              // blank line ends the headers
        size_t p = line.find(':');
        if(p == string::npos) continue;
        string k = line.substr(0, p);
        string v = line.substr(p+1);
        while(!v.empty() && v.front() == ' ') v.erase(v.begin());
        hdr[k] = v;
    }

    cout << "headers (" << hdr.size() << "):\n";
    for(auto &h : hdr)
        cout << "  " << h.first << " = " << h.second << "\n";
    return 0;
}
