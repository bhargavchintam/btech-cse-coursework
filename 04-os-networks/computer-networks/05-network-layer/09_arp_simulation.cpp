// arp simulation - resolve an ip to a mac by broadcast request/reply, keep an arp cache
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Entry { string ip, mac; };

int main()
{
    // the machines actually on this lan (what a broadcast would reach)
    vector<Entry> lan = {
        { "192.168.1.1", "aa:bb:cc:00:00:01" },
        { "192.168.1.2", "aa:bb:cc:00:00:02" },
        { "192.168.1.5", "aa:bb:cc:00:00:05" },
        { "192.168.1.7", "aa:bb:cc:00:00:07" },
    };
    vector<Entry> cache;

    cout << "ip(s) to resolve, one per line:\n";
    string ip;
    while(cin >> ip){
        bool hit = false;
        for(size_t i = 0; i < cache.size(); i++)
            if(cache[i].ip == ip){
                cout << ip << " -> " << cache[i].mac << "  (cache hit)\n";
                hit = true;
                break;
            }
        if(hit) continue;

        cout << "ARP request (broadcast): who has " << ip << "?\n";
        bool found = false;
        for(size_t i = 0; i < lan.size(); i++)
            if(lan[i].ip == ip){
                cout << "ARP reply: " << ip << " is at " << lan[i].mac << "\n";
                cache.push_back({ ip, lan[i].mac });
                found = true;
                break;
            }
        if(!found)
            cout << "no reply, " << ip << " unreachable\n";
    }

    cout << "\narp cache\n";
    for(size_t i = 0; i < cache.size(); i++)
        cout << cache[i].ip << "  " << cache[i].mac << "\n";
    return 0;
}
