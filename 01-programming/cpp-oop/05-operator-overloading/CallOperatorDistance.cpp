// adding two distances using the function call () operator

#include<iostream>
using namespace std;

class Distance
{
    int feet, inch;
public:
    Distance()
    {
        feet = 0;
        inch = 0;
    }
    Distance(int f, int i)
    {
        feet = f;
        inch = i;
    }
    Distance operator()(Distance d)
    {
        Distance temp;
        temp.inch = inch + d.inch;
        temp.feet = feet + d.feet;
        if(temp.inch >= 12)
        {
            temp.feet++;
            temp.inch = temp.inch - 12;
        }
        return temp;
    }
    void display()
    {
        cout<<feet<<" feet "<<inch<<" inch"<<endl;
    }
};

int main()
{
    Distance d1(5, 8), d2(3, 7), d3;
    d3 = d1(d2);
    cout<<"d1 = "; d1.display();
    cout<<"d2 = "; d2.display();
    cout<<"sum = "; d3.display();
    return 0;
}
