/* Lab Program 3
   Write a C++ program to add two complex numbers using operator overloading.
   g++ -std=c++14 Lab03_ComplexAddition.cpp -o lab03 */

#include<iostream>
using namespace std;

class Complex
{
    float real, imag;
    public:
        void read()
        {
            cin>>real>>imag;
        }
        Complex operator+(Complex c)
        {
            Complex temp;
            temp.real = real + c.real;
            temp.imag = imag + c.imag;
            return temp;
        }
        void show()
        {
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
};

int main()
{
    Complex c1, c2, c3;
    cout<<"Enter first complex number (real imag) : ";
    c1.read();
    cout<<"Enter second complex number (real imag) : ";
    c2.read();

    c3 = c1 + c2;
    cout<<"Sum = ";
    c3.show();
    return 0;
}
