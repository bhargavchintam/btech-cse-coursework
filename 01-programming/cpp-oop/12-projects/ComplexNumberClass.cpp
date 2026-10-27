// complex number class with operator overloading
#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    double real;
    double imag;
public:
    Complex()
    {
        real=0;
        imag=0;
    }
    Complex(double r,double i)
    {
        real=r;
        imag=i;
    }
    Complex operator+(Complex c)
    {
        Complex t;
        t.real=real+c.real;
        t.imag=imag+c.imag;
        return t;
    }
    Complex operator-(Complex c)
    {
        Complex t;
        t.real=real-c.real;
        t.imag=imag-c.imag;
        return t;
    }
    Complex operator*(Complex c)
    {
        Complex t;
        t.real=real*c.real - imag*c.imag;
        t.imag=real*c.imag + imag*c.real;
        return t;
    }
    double magnitude()
    {
        return sqrt(real*real + imag*imag);
    }
    friend ostream& operator<<(ostream &out,Complex c);
};

ostream& operator<<(ostream &out,Complex c)
{
    out<<c.real;
    if(c.imag>=0)
        out<<" + "<<c.imag<<"i";
    else
        out<<" - "<<(-c.imag)<<"i";
    return out;
}

int main()
{
    double a,b,c,d;
    cout<<"enter first complex number (real imag) : ";
    cin>>a>>b;
    cout<<"enter second complex number (real imag) : ";
    cin>>c>>d;

    Complex c1(a,b);
    Complex c2(c,d);

    Complex sum = c1+c2;
    Complex diff = c1-c2;
    Complex prod = c1*c2;

    cout<<"c1 = "<<c1<<endl;
    cout<<"c2 = "<<c2<<endl;
    cout<<"sum = "<<sum<<endl;
    cout<<"difference = "<<diff<<endl;
    cout<<"product = "<<prod<<endl;
    cout<<"magnitude of c1 = "<<c1.magnitude()<<endl;

    return 0;
}
