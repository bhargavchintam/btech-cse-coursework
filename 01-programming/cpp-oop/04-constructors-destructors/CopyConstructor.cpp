// copy constructor

#include<iostream>
using namespace std;

class sample
{
    int a,b;
    public:
        sample(int x,int y)
        {
            a=x;
            b=y;
        }
        sample(sample &s)
        {
            a=s.a;
            b=s.b;
        }
        void show()
        {
            cout<<"a = "<<a<<" b = "<<b<<endl;
        }
};

int main()
{
    sample s1(10,20);
    sample s2(s1);    // copy constructor called
    cout<<"s1 : ";
    s1.show();
    cout<<"s2 : ";
    s2.show();
    return 0;
}
