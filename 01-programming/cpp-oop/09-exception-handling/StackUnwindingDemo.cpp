// destructors of local objects are called when the stack unwinds
#include<iostream>
using namespace std;

class test
{
    int id;
public:
    test(int i)
    {
        id=i;
        cout<<"constructed "<<id<<endl;
    }
    ~test()
    {
        cout<<"destructed "<<id<<endl;
    }
};

void func()
{
    test t1(1);
    test t2(2);
    cout<<"about to throw"<<endl;
    throw 99;
}

int main()
{
    try
    {
        func();
    }
    catch(int e)
    {
        cout<<"caught "<<e<<" in main"<<endl;
    }
    return 0;
}
