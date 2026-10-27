// function overloading - area of different shapes
#include<iostream>
using namespace std;

float area(float r)
{
    return 3.14 * r * r;
}

float area(float l, float b)
{
    return l * b;
}

float area(float base, float height, int t)
{
    return 0.5 * base * height;
}

int main()
{
    cout<<"Area of circle = "<<area(5.0f)<<endl;
    cout<<"Area of rectangle = "<<area(4.0f, 6.0f)<<endl;
    cout<<"Area of triangle = "<<area(4.0f, 6.0f, 1)<<endl;
    return 0;
}
