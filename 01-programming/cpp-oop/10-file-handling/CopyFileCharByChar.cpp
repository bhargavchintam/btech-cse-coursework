// copy one file to another character by character
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    ofstream fout("copy.txt");
    if(!fin)
    {
        cout<<"source file not found"<<endl;
        return 1;
    }
    char ch;
    while(fin.get(ch))
    {
        fout.put(ch);
    }
    fin.close();
    fout.close();
    cout<<"file copied successfully"<<endl;
    return 0;
}
