// character stuffing - DLE STX ... DLE ETX framing, DLE doubled inside the data

#include<iostream>
#include<string>
using namespace std;

const char DLE = 0x10;
const char STX = 0x02;
const char ETX = 0x03;

string name(char c){
    if(c==DLE) return "DLE";
    if(c==STX) return "STX";
    if(c==ETX) return "ETX";
    return string(1,c);
}

void show(const string& f){
    for(size_t i=0;i<f.size();i++){
        cout<<name(f[i]);
        if(i+1<f.size()) cout<<' ';
    }
    cout<<"\n";
}

string stuff(const string& data){
    string f;
    f += DLE; f += STX;
    for(size_t i=0;i<data.size();i++){
        if(data[i]==DLE) f += DLE;      // double it
        f += data[i];
    }
    f += DLE; f += ETX;
    return f;
}

string destuff(const string& f){
    string data;
    size_t i = 2;                        // skip opening DLE STX
    while(i < f.size()-2){               // stop before closing DLE ETX
        if(f[i]==DLE && f[i+1]==DLE){
            data += DLE; i += 2;
        } else {
            data += f[i]; i++;
        }
    }
    return data;
}

int main(){
    string data = "HI";
    data += DLE;                         // a DLE sitting in the payload
    data += "OK";

    cout<<"payload  : "; show(data);
    string f = stuff(data);
    cout<<"framed   : "; show(f);
    string back = destuff(f);
    cout<<"destuffed: "; show(back);
    cout<<"match    : "<<(back==data ? "yes":"no")<<"\n";
    return 0;
}
