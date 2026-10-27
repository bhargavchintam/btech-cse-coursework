// internet checksum - 1s complement sum of 16-bit words

#include<iostream>
#include<cstdint>
#include<iomanip>
using namespace std;

uint16_t checksum(const uint16_t* w, int n){
    uint32_t sum = 0;
    for(int i=0;i<n;i++){
        sum += w[i];
        sum = (sum & 0xFFFF) + (sum >> 16);   // fold the carry back in
    }
    return (uint16_t)~sum;
}

int main(){
    uint16_t data[] = {0x4500, 0x003C, 0x1C46, 0x4000, 0x4006};
    int n = sizeof(data)/sizeof(data[0]);

    uint16_t cs = checksum(data, n);
    cout<<hex<<uppercase<<setfill('0');
    cout<<"checksum: "<<setw(4)<<cs<<"\n";

    // receiver folds data + checksum, complement should come out 0
    uint32_t sum = 0;
    for(int i=0;i<n;i++){ sum += data[i]; sum = (sum&0xFFFF)+(sum>>16); }
    sum += cs; sum = (sum&0xFFFF)+(sum>>16);
    uint16_t chk = (uint16_t)~sum;
    cout<<"receiver: "<<setw(4)<<chk<<(chk==0 ? "  ok":"  error")<<"\n";
    return 0;
}
