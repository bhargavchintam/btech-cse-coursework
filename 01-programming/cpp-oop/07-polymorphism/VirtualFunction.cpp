#include<iostream>
using namespace std;

class base
{
    public:
        virtual void display()
        {
            cout<<"base display"<<endl;
        }
};

class derived : public base
{
    public:
        void display()
        {
            cout<<"derived display"<<endl;
        }
};

int main()
{
    base *bp;
    derived d;
    bp = &d;
    bp->display();      // calls derived version because it is virtual
    return 0;
}
