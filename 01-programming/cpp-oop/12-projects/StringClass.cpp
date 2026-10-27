// mystring class - a small string implementation using char*
#include<iostream>
#include<cstring>
using namespace std;

class mystring
{
    char *str;
public:
    mystring()
    {
        str=new char[1];
        str[0]='\0';
    }
    mystring(const char *s)
    {
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }
    mystring(const mystring &m)     // deep copy else both point to same memory
    {
        str=new char[strlen(m.str)+1];
        strcpy(str,m.str);
    }
    mystring& operator=(const mystring &m)
    {
        if(this==&m)
            return *this;
        delete[] str;
        str=new char[strlen(m.str)+1];
        strcpy(str,m.str);
        return *this;
    }
    ~mystring()
    {
        delete[] str;
    }
    int length()
    {
        return strlen(str);
    }
    mystring concat(mystring m)
    {
        char *temp=new char[strlen(str)+strlen(m.str)+1];
        strcpy(temp,str);
        strcat(temp,m.str);
        mystring res(temp);
        delete[] temp;
        return res;
    }
    int compare(mystring m)
    {
        return strcmp(str,m.str);
    }
    void display()
    {
        cout<<str<<endl;
    }
};

int main()
{
    mystring s1("hello");
    mystring s2("world");

    cout<<"s1 = ";
    s1.display();
    cout<<"s2 = ";
    s2.display();

    cout<<"length of s1 = "<<s1.length()<<endl;

    mystring s3 = s1.concat(s2);
    cout<<"after concat = ";
    s3.display();

    if(s1.compare(s2)==0)
        cout<<"s1 and s2 are equal"<<endl;
    else
        cout<<"s1 and s2 are not equal"<<endl;

    mystring s4 = s1;    // copy constructor called
    cout<<"copy of s1 = ";
    s4.display();

    return 0;
}
