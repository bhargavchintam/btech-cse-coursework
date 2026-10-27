/* Bindu Bhargava   16-09-19 */
// two dimensional parity - detect and locate a single bit error

#include<iostream>
using namespace std;

const int R=4, C=8;

void rowpar(int m[R][C], int rp[R]){
    for(int i=0;i<R;i++){
        int s=0;
        for(int j=0;j<C;j++) s^=m[i][j];
        rp[i]=s;
    }
}
void colpar(int m[R][C], int cp[C]){
    for(int j=0;j<C;j++){
        int s=0;
        for(int i=0;i<R;i++) s^=m[i][j];
        cp[j]=s;
    }
}

int main(){
    int m[R][C] = {
        {1,0,0,1,0,1,1,0},
        {1,1,0,0,1,0,1,1},
        {0,1,1,1,0,0,0,1},
        {1,0,1,0,1,1,0,0}
    };
    int rp[R], cp[C];
    rowpar(m, rp);
    colpar(m, cp);

    int er=2, ec=5;
    m[er][ec] ^= 1;                         // one bit flips on the wire
    cout<<"injected error at ("<<er<<","<<ec<<")\n";

    int nrp[R], ncp[C];
    rowpar(m, nrp);
    colpar(m, ncp);

    int br=-1, bc=-1;
    for(int i=0;i<R;i++) if(rp[i]!=nrp[i]) br=i;
    for(int j=0;j<C;j++) if(cp[j]!=ncp[j]) bc=j;

    if(br>=0 && bc>=0){
        cout<<"error located at ("<<br<<","<<bc<<")\n";
        m[br][bc]^=1;
        cout<<"corrected\n";
    } else cout<<"no error detected\n";
    return 0;
}
