#include<iostream>
using namespace std;

class shape
{
    public:
        virtual float area() = 0;
};

class circle : public shape
{
    float r;
    public:
        circle(float x)
        {
            r = x;
        }
        float area()
        {
            return 3.14 * r * r;
        }
};

class rectangle : public shape
{
    float l, b;
    public:
        rectangle(float x, float y)
        {
            l = x;
            b = y;
        }
        float area()
        {
            return l * b;
        }
};

int main()
{
    circle c(5);
    rectangle r(4, 6);
    cout<<"Area of circle = "<<c.area()<<endl;
    cout<<"Area of rectangle = "<<r.area()<<endl;
    return 0;
}
