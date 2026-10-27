// default arguments
#include<iostream>
using namespace std;

float amount(float principal, int years, float rate = 0.10);

int main()
{
    cout<<"With default rate : "<<amount(5000, 2)<<endl;
    cout<<"With given rate : "<<amount(5000, 2, 0.15)<<endl;
    return 0;
}

float amount(float principal, int years, float rate)
{
    return principal + principal * years * rate;
}
