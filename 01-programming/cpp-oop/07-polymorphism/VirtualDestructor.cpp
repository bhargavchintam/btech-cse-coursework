#include<iostream>
using namespace std;

class base
{
    public:
        base()
        {
            cout<<"base constructor"<<endl;
        }
        virtual ~base()     // virtual so derived dtor also runs
        {
            cout<<"base destructor"<<endl;
        }
};

class derived : public base
{
    int *p;
    public:
        derived()
        {
            p = new int[5];
            cout<<"derived constructor"<<endl;
        }
        ~derived()
        {
            delete[] p;
            cout<<"derived destructor"<<endl;
        }
};

int main()
{
    base *bp = new derived();
    delete bp;
    return 0;
}
