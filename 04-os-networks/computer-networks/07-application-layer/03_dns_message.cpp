// dns query message - build the 12-byte header + question, then parse it back. no live lookup.
#include<iostream>
#include<string>
#include<vector>
#include<cstdint>
#include<cstdio>
using namespace std;

void put16(vector<uint8_t> &b, uint16_t v)
{
    b.push_back((uint8_t)(v >> 8));        // big endian = network byte order
    b.push_back((uint8_t)(v & 0xff));
}

uint16_t get16(const vector<uint8_t> &b, size_t i)
{
    return (uint16_t)((b[i] << 8) | b[i+1]);
}

void encode_name(vector<uint8_t> &b, const string &name)
{
    size_t start = 0;
    while(start < name.size()){
        size_t dot = name.find('.', start);
        if(dot == string::npos) dot = name.size();
        b.push_back((uint8_t)(dot - start));      // each label is length-prefixed
        for(size_t i = start; i < dot; i++)
            b.push_back((uint8_t)name[i]);
        start = dot + 1;
    }
    b.push_back(0);                               // root label ends the name
}

int main()
{
    string qname = "www.example.com";
    vector<uint8_t> msg;

    put16(msg, 0x1a2b);    // id
    put16(msg, 0x0100);    // flags: standard query, RD=1
    put16(msg, 1);         // qdcount
    put16(msg, 0);         // ancount
    put16(msg, 0);         // nscount
    put16(msg, 0);         // arcount

    encode_name(msg, qname);
    put16(msg, 1);         // qtype  A
    put16(msg, 1);         // qclass IN

    printf("message is %zu bytes:\n", msg.size());
    for(size_t i = 0; i < msg.size(); i++){
        printf("%02x ", msg[i]);
        if((i+1) % 12 == 0) printf("\n");
    }
    printf("\n\n");

    printf("id      = 0x%04x\n", get16(msg, 0));
    uint16_t flags = get16(msg, 2);
    printf("flags   = 0x%04x  (QR=%d RD=%d)\n", flags, (flags >> 15) & 1, (flags >> 8) & 1);
    printf("qdcount = %d\n", get16(msg, 4));

    // question section starts right after the 12-byte header
    size_t p = 12;
    string name;
    while(msg[p] != 0){
        int len = msg[p++];               // labels are length-prefixed, not null terminated
        if(!name.empty()) name += ".";
        for(int i = 0; i < len; i++) name += (char)msg[p++];
    }
    p++;                                  // skip the terminating zero
    uint16_t qtype = get16(msg, p); p += 2;
    uint16_t qclass = get16(msg, p); p += 2;

    printf("qname   = %s\n", name.c_str());
    printf("qtype   = %d (A)\n", qtype);
    printf("qclass  = %d (IN)\n", qclass);
    return 0;
}
