// program to add two complex numbers using operator overloading

#include<iostream>
using namespace std;

class Complex
{
    float real, imag;
public:
    Complex() { }
    Complex(float r, float i) {
        real = r;
        imag = i;
    }
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    void display() {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

int main()
{
    Complex c1(2.5, 3.5), c2(1.6, 2.7), c3;
    c3 = c1 + c2;
    cout<<"c1 = "; c1.display();
    cout<<"c2 = "; c2.display();
    cout<<"c3 = "; c3.display();
    return 0;
}
