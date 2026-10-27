// overloading insertion operator << as friend for complex class

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
    friend ostream& operator<<(ostream &out, Complex c);
};

ostream& operator<<(ostream &out, Complex c)
{
    out<<c.real<<" + "<<c.imag<<"i";
    return out;
}

int main()
{
    Complex c1(4.5, 6.2), c2(2.0, 3.3);
    cout<<"c1 = "<<c1<<endl;
    cout<<"c2 = "<<c2<<endl;
    return 0;
}
