// implicit and explicit type conversion
#include<iostream>
using namespace std;

int main()
{
    int a = 7, b = 2;
    float avg;

    avg = a / b;                         // implicit, still integer division here
    cout<<"Without cast avg = "<<avg<<endl;

    avg = static_cast<float>(a) / b;     // explicit conversion
    cout<<"With cast avg = "<<avg<<endl;

    double d = 9.99;
    int x = (int)d;                      // c-style cast, fraction lost
    cout<<"Double "<<d<<" to int = "<<x<<endl;
    return 0;
}
