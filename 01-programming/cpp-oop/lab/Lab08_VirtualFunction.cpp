/* Lab Program 8
   Write a C++ program to find the area of shapes using virtual functions (runtime polymorphism).
   g++ -std=c++14 Lab08_VirtualFunction.cpp -o lab08 */

#include<iostream>
using namespace std;

class shape
{
    public:
        virtual void area()
        {
            cout<<"area of shape"<<endl;
        }
};

class circle : public shape
{
    float r;
    public:
        circle(float x)
        {
            r = x;
        }
        void area()
        {
            cout<<"Area of circle = "<<3.14*r*r<<endl;
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
        void area()
        {
            cout<<"Area of rectangle = "<<l*b<<endl;
        }
};

int main()
{
    float r, l, b;
    cout<<"Enter radius of circle : ";
    cin>>r;
    cout<<"Enter length and breadth of rectangle : ";
    cin>>l>>b;

    shape *p;                 // base pointer decides at run time
    circle c(r);
    rectangle rt(l,b);

    p = &c;
    p->area();
    p = &rt;
    p->area();
    return 0;
}
