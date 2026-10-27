// overloading < operator to compare two time objects

#include<iostream>
using namespace std;

class mytime
{
    int hr, mn;
public:
    mytime(int h, int m)
    {
        hr = h;
        mn = m;
    }
    bool operator<(mytime t)
    {
        if(hr < t.hr)
            return true;
        else if(hr == t.hr && mn < t.mn)
            return true;
        return false;
    }
};

int main()
{
    mytime t1(10, 45), t2(11, 20);
    if(t1 < t2)
        cout<<"t1 is earlier than t2"<<endl;
    else
        cout<<"t1 is not earlier than t2"<<endl;
    return 0;
}
