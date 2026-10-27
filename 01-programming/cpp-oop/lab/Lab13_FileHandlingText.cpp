/* Lab Program 13
   Write a C++ program to write text to a file and read it back.
   g++ -std=c++14 Lab13_FileHandlingText.cpp -o lab13 */

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("notes.txt");
    fout<<"C++ file handling"<<endl;
    fout<<"reading and writing text"<<endl;
    fout.close();

    ifstream fin("notes.txt");
    char line[80];
    cout<<"File contents :"<<endl;
    while(fin.getline(line,80))
        cout<<line<<endl;
    fin.close();
    return 0;
}
