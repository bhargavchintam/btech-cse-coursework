// function overriding - derived redefines base function
#include<iostream>
using namespace std;

class base
{
    public:
        void show()
        {
            cout<<"show from base"<<endl;
        }
};

class derived : public base
{
    public:
        void show()
        {
            cout<<"show from derived"<<endl;
        }
};

int main()
{
    derived d;
    d.show();
    d.base::show();
    return 0;
}
