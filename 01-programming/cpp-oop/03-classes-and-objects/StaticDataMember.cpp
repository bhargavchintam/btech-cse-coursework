// static data member as object counter

#include<iostream>
using namespace std;

class item
{
    int code;
    static int count;
    public:
        void setcode()
        {
            count++;
            code=count;
        }
        void showcode()
        {
            cout<<"Object number "<<code<<endl;
        }
        void showcount()
        {
            cout<<"Count = "<<count<<endl;
        }
};

int item::count;

int main()
{
    item a,b,c;
    a.setcode();
    b.setcode();
    c.setcode();
    a.showcode();
    b.showcode();
    c.showcode();
    c.showcount();
    return 0;
}
