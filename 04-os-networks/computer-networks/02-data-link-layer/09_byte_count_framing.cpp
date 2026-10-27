// byte-count framing - each frame prefixed by a count (count includes itself)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string> frames = {"HELLO", "HI", "BYE!!"};

    vector<int> stream;
    for(size_t f=0; f<frames.size(); f++){
        stream.push_back((int)frames[f].size()+1);      // the count byte
        for(size_t i=0;i<frames[f].size();i++)
            stream.push_back(frames[f][i]);
    }

    cout<<"stream: ";
    for(size_t i=0;i<stream.size();i++){
        if(stream[i] < 32) cout<<stream[i]<<" ";         // a count field
        else cout<<(char)stream[i]<<" ";
    }
    cout<<"\n";

    size_t i = 0;
    while(i < stream.size()){
        int cnt = stream[i];
        string f;
        for(int k=1;k<cnt;k++) f += (char)stream[i+k];
        cout<<"count "<<cnt<<" -> "<<f<<"\n";
        i += cnt;
    }
    return 0;
}
