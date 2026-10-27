// passing arguments to the base class constructor

#include<iostream>
using namespace std;

class base
{
    int a;
public:
    base(int x)
    {
        a = x;
    }
    void showa()
    {
        cout<<"a = "<<a<<endl;
    }
};

class derived : public base
{
    int b;
public:
    derived(int x, int y) : base(x)
    {
        b = y;
    }
    void showb()
    {
        cout<<"b = "<<b<<endl;
    }
};

int main()
{
    derived d(10, 20);
    d.showa();
    d.showb();
    return 0;
}
