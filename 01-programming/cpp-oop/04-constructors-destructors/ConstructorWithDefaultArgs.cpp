// constructor with default arguments

#include<iostream>
using namespace std;

class interest
{
    float amount,rate,si;
    public:
        interest(float p,float r=2.5)
        {
            amount=p;
            rate=r;
        }
        void calculate()
        {
            si=amount*rate/100;
            cout<<"Interest = "<<si<<endl;
        }
};

int main()
{
    interest a(1000);
    interest b(1000,5.0);
    a.calculate();
    b.calculate();
    return 0;
}
