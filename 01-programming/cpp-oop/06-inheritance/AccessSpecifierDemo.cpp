// demonstration of private, protected and public access specifiers

#include<iostream>
using namespace std;

class demo
{
private:
    int a;
protected:
    int b;
public:
    int c;
    void setdata(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    void showdata()
    {
        cout<<"private a = "<<a<<endl;
        cout<<"protected b = "<<b<<endl;
        cout<<"public c = "<<c<<endl;
    }
};

int main()
{
    demo d;
    d.setdata(1, 2, 3);
    d.c = 30;           // public member can be accessed directly
    d.showdata();
    return 0;
}
