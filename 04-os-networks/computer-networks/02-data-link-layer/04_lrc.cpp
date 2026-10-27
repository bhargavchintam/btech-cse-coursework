// LRC - longitudinal redundancy check over a block of bytes

#include<iostream>
#include<bitset>
using namespace std;

int main(){
    unsigned char block[] = {0x1C, 0xA3, 0x5F, 0x77};
    int n = sizeof(block);

    unsigned char lrc = 0;
    for(int i=0;i<n;i++){
        lrc ^= block[i];                 // column-wise even parity
        cout<<bitset<8>(block[i])<<"\n";
    }
    cout<<"--------\n";
    cout<<bitset<8>(lrc)<<"  LRC\n";

    unsigned char chk = lrc;
    for(int i=0;i<n;i++) chk ^= block[i];
    cout<<"receiver: "<<(chk==0 ? "ok":"error")<<"\n";
    return 0;
}
