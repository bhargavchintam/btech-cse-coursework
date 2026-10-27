// bit stuffing / de-stuffing with flag 01111110

#include<iostream>
#include<string>
using namespace std;

string flag = "01111110";

string stuff(string in){
    string out;
    int ones = 0;
    for(size_t i=0;i<in.size();i++){
        out += in[i];
        if(in[i]=='1'){
            ones++;
            if(ones==5){ out += '0'; ones=0; }   // break the run so it cant look like a flag
        } else ones=0;
    }
    return flag + out + flag;
}

string destuff(string f){
    string in = f.substr(flag.size(), f.size()-2*flag.size());
    string out;
    int ones=0;
    for(size_t i=0;i<in.size();i++){
        out += in[i];
        if(in[i]=='1'){
            ones++;
            if(ones==5){ i++; ones=0; }           // drop the stuffed 0
        } else ones=0;
    }
    return out;
}

int main(){
    string data;
    cout<<"enter bit string: ";
    cin>>data;

    string framed = stuff(data);
    cout<<"stuffed frame : "<<framed<<"\n";
    cout<<"de-stuffed    : "<<destuff(framed)<<"\n";
    cout<<"match         : "<<(destuff(framed)==data ? "yes":"no")<<"\n";
    return 0;
}
