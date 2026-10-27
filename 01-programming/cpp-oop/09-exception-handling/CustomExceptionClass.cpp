// user defined exception class
#include<iostream>
#include<string>
using namespace std;

class myexception
{
    string msg;
public:
    myexception(string m)
    {
        msg=m;
    }
    string what()
    {
        return msg;
    }
};

int main()
{
    int age;
    cout<<"Enter age : ";
    cin>>age;
    try
    {
        if(age<0)
            throw myexception("age cannot be negative");
        if(age>150)
            throw myexception("age is too large");
        cout<<"Age is "<<age<<endl;
    }
    catch(myexception e)
    {
        cout<<"Exception : "<<e.what()<<endl;
    }
    return 0;
}
