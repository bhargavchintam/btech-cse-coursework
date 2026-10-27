// static member function

#include<iostream>
using namespace std;

class item
{
    static int count;
    int number;
    public:
        void getdata(int a)
        {
            number=a;
            count++;
        }
        void shownumber()
        {
            cout<<"Number = "<<number<<endl;
        }
        static void getcount()
        {
            cout<<"Count = "<<count<<endl;
        }
};

int item::count;

int main()
{
    item a,b,c;
    a.getdata(100);
    b.getdata(200);
    item::getcount();
    c.getdata(300);
    a.shownumber();
    item::getcount();
    return 0;
}
