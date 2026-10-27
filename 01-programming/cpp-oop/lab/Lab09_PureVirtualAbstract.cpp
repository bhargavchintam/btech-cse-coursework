/* Lab Program 9
   Write a C++ program to demonstrate an abstract class using a pure virtual function.
   g++ -std=c++14 Lab09_PureVirtualAbstract.cpp -o lab09 */

#include<iostream>
using namespace std;

class shape
{
    public:
        virtual void area() = 0;      // pure virtual makes shape abstract
};

class triangle : public shape
{
    float b, h;
    public:
        triangle(float x, float y)
        {
            b = x;
            h = y;
        }
        void area()
        {
            cout<<"Area of triangle = "<<0.5*b*h<<endl;
        }
};

class square : public shape
{
    float s;
    public:
        square(float x)
        {
            s = x;
        }
        void area()
        {
            cout<<"Area of square = "<<s*s<<endl;
        }
};

int main()
{
    shape *p;
    triangle t(4,5);
    square sq(6);

    p = &t;
    p->area();
    p = &sq;
    p->area();
    return 0;
}
