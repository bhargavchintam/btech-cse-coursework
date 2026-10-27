#include<iostream>
using namespace std;

class base
{
    public:
        int a;
        void show()
        {
            cout<<"a = "<<a<<endl;
        }
};

class derived : public base
{
    public:
        int b;
        void show()
        {
            cout<<"a = "<<a<<" b = "<<b<<endl;
        }
};

int main()
{
    derived d;
    base *bp = &d;      // base pointer to derived object
    bp->a = 10;
    // bp->b = 20;      not allowed, b belongs to derived

    derived *dp = &d;
    dp->b = 20;

    bp->show();
    dp->show();
    return 0;
}
