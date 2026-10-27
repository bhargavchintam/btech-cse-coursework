// private inheritance

#include<iostream>
using namespace std;

class base
{
    int x;
public:
    void setx(int a)
    {
        x = a;
    }
    void showx()
    {
        cout<<"x = "<<x<<endl;
    }
};

class derived : private base
{
    int y;
public:
    void setdata(int a, int b)
    {
        setx(a);          // public members of base become private in derived
        y = b;
    }
    void showdata()
    {
        showx();
        cout<<"y = "<<y<<endl;
    }
};

int main()
{
    derived d;
    d.setdata(5, 10);
    d.showdata();
    // d.showx();  not accessible because of private inheritance
    return 0;
}
