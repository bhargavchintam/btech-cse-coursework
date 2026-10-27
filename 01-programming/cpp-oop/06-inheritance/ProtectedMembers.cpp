// accessing protected members in a derived class

#include<iostream>
using namespace std;

class base
{
protected:
    int num;
public:
    void setnum(int n)
    {
        num = n;
    }
};

class derived : public base
{
public:
    void show()
    {
        num = num + 5;      // protected member is accessible here
        cout<<"num = "<<num<<endl;
    }
};

int main()
{
    derived d;
    d.setnum(10);
    d.show();
    return 0;
}
