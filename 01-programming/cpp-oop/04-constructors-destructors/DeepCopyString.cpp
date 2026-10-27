// deep copy constructor

#include<iostream>
#include<cstring>
using namespace std;

class mystring
{
    char *data;
    int len;
    public:
        mystring(const char *s)
        {
            len=strlen(s);
            data=new char[len+1];
            strcpy(data,s);
        }
        mystring(const mystring &s)
        {
            len=s.len;
            data=new char[len+1];    // deep copy else both point to same memory
            strcpy(data,s.data);
        }
        void show()
        {
            cout<<data<<endl;
        }
        ~mystring()
        {
            delete[] data;
        }
};

int main()
{
    mystring s1("hello");
    mystring s2=s1;
    cout<<"s1 = ";
    s1.show();
    cout<<"s2 = ";
    s2.show();
    return 0;
}
