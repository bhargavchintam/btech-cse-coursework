#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    if(!fin)
    {
        cout<<"cannot open file"<<endl;
        return 1;
    }
    int lines=0,words=0,chars=0;
    char ch;
    bool inword=false;
    while(fin.get(ch))
    {
        chars++;
        if(ch=='\n')
            lines++;
        if(ch==' '||ch=='\n'||ch=='\t')
            inword=false;
        else if(inword==false)
        {
            inword=true;
            words++;
        }
    }
    fin.close();
    cout<<"Lines = "<<lines<<endl;
    cout<<"Words = "<<words<<endl;
    cout<<"Characters = "<<chars<<endl;
    return 0;
}
