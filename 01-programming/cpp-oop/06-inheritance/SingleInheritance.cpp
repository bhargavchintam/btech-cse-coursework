// single inheritance

#include<iostream>
using namespace std;

class base
{
public:
    void show_base()
    {
        cout<<"this is the base class"<<endl;
    }
};

class derived : public base
{
public:
    void show_derived()
    {
        cout<<"this is the derived class"<<endl;
    }
};

int main()
{
    derived d;
    d.show_base();
    d.show_derived();
    return 0;
}
