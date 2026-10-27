#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream fin("data.txt");
    if(!fin) {
        cout<<"cannot open file"<<endl;
        return 1;
    }
    string line;
    while(getline(fin,line)) {
        cout<<line<<"\n";
    }
    fin.close();
    return 0;
}
