// adding two complex numbers using a friend function

#include<iostream>
using namespace std;

class Complex
{
    float real, imag;
public:
    Complex() { }
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }
    friend Complex operator+(Complex a, Complex b);
    void display()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

Complex operator+(Complex a, Complex b)
{
    Complex temp;
    temp.real = a.real + b.real;   // friend can access private
    temp.imag = a.imag + b.imag;
    return temp;
}

int main()
{
    Complex c1(3.1, 2.2), c2(1.4, 5.5), c3;
    c3 = c1 + c2;
    cout<<"sum = ";
    c3.display();
    return 0;
}
