// hierarchical inheritance

#include<iostream>
using namespace std;

class shape
{
protected:
    float x, y;
public:
    void getdata(float a, float b)
    {
        x = a;
        y = b;
    }
};

class rectangle : public shape
{
public:
    void area()
    {
        cout<<"area of rectangle = "<<x * y<<endl;
    }
};

class triangle : public shape
{
public:
    void area()
    {
        cout<<"area of triangle = "<<0.5 * x * y<<endl;
    }
};

int main()
{
    rectangle r;
    triangle t;
    r.getdata(10, 5);
    r.area();
    t.getdata(10, 5);
    t.area();
    return 0;
}
