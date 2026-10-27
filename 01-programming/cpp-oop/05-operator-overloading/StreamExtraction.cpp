// overloading extraction operator >> as friend for complex class

#include<iostream>
using namespace std;

class Complex
{
    float real, imag;
public:
    friend istream& operator>>(istream &in, Complex &c);
    friend ostream& operator<<(ostream &out, Complex c);
};

istream& operator>>(istream &in, Complex &c)
{
    cout<<"enter real and imaginary part : ";
    in>>c.real>>c.imag;
    return in;
}

ostream& operator<<(ostream &out, Complex c)
{
    out<<c.real<<" + "<<c.imag<<"i";
    return out;
}

int main()
{
    Complex c1;
    cin>>c1;
    cout<<"you entered : "<<c1<<endl;
    return 0;
}
