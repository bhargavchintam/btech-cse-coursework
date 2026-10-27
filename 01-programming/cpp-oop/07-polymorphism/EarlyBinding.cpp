#include<iostream>
using namespace std;

class base
{
    public:
        void show()
        {
            cout<<"base show"<<endl;
        }
};

class derived : public base
{
    public:
        void show()
        {
            cout<<"derived show"<<endl;
        }
};

int main()
{
    base *bp;
    derived d;
    bp = &d;
    bp->show();     // early binding, calls base
    return 0;
}
