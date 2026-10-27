/* Bindu Bhargava  12-11-19 */
#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("data.txt");
    fout<<"Hello world"<<endl;
    fout<<"This is a file handling program"<<endl;
    fout<<"C plus plus file streams"<<endl;
    fout.close();
    cout<<"data written to file"<<endl;
    return 0;
}
