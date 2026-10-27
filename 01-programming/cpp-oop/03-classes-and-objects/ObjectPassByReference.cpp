// passing object by reference

#include<iostream>
using namespace std;

class number
{
    int n;
    public:
        void setn(int a)
        {
            n=a;
        }
        void show()
        {
            cout<<n<<endl;
        }
        friend void swapobj(number &a,number &b);
};

void swapobj(number &a,number &b)
{
    number t=a;
    a=b;
    b=t;
}

int main()
{
    number x,y;
    x.setn(10);
    y.setn(20);
    swapobj(x,y);
    cout<<"After swap"<<endl;
    x.show();
    y.show();
    return 0;
}
