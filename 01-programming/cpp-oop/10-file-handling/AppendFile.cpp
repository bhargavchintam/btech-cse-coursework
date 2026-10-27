#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream fout("data.txt",ios::app);
    fout<<"this line is appended at the end"<<endl;
    fout.close();
    cout<<"line appended"<<endl;
    return 0;
}
