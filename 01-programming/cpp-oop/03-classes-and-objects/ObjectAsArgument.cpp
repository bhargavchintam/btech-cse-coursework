// passing object as argument by value

#include<iostream>
using namespace std;

class Time
{
    int hr,min;
    public:
        void getdata(int h,int m)
        {
            hr=h;
            min=m;
        }
        void sum(Time t1,Time t2)
        {
            min=t1.min+t2.min;
            hr=min/60;
            min=min%60;
            hr=hr+t1.hr+t2.hr;
        }
        void putdata()
        {
            cout<<hr<<" hrs "<<min<<" min"<<endl;
        }
};

int main()
{
    Time a,b,c;
    a.getdata(2,45);
    b.getdata(3,30);
    c.sum(a,b);
    cout<<"Total time = ";
    c.putdata();
    return 0;
}
