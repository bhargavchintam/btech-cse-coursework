#include<iostream>
using namespace std;

class shape
{
    public:
        virtual double area() = 0;
        virtual ~shape() { }
};

class square : public shape
{
    double s;
    public:
        square(double x) { s = x; }
        double area() { return s * s; }
};

class triangle : public shape
{
    double b, h;
    public:
        triangle(double x, double y) { b = x; h = y; }
        double area() { return 0.5 * b * h; }
};

class circle : public shape
{
    double r;
    public:
        circle(double x) { r = x; }
        double area() { return 3.1416 * r * r; }
};

int main()
{
    shape *s[3];
    s[0] = new square(4);
    s[1] = new triangle(3, 6);
    s[2] = new circle(5);

    for(int i = 0; i < 3; i++)
        cout<<"area = "<<s[i]->area()<<endl;

    for(int i = 0; i < 3; i++)
        delete s[i];

    return 0;
}
