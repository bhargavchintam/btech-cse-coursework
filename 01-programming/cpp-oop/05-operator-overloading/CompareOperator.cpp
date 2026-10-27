// overloading == operator to compare two objects

#include<iostream>
using namespace std;

class Distance
{
    int feet, inch;
public:
    Distance(int f, int i)
    {
        feet = f;
        inch = i;
    }
    int operator==(Distance d)
    {
        if(feet == d.feet && inch == d.inch)
            return 1;
        else
            return 0;
    }
};

int main()
{
    Distance d1(5, 6), d2(5, 6), d3(4, 11);
    if(d1 == d2)
        cout<<"d1 and d2 are equal"<<endl;
    else
        cout<<"d1 and d2 are not equal"<<endl;
    if(d1 == d3)
        cout<<"d1 and d3 are equal"<<endl;
    else
        cout<<"d1 and d3 are not equal"<<endl;
    return 0;
}
