// function throws the exception, main catches it
#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n<0)
        throw "number is negative";
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    try
    {
        cout<<"Factorial = "<<factorial(n)<<endl;
    }
    catch(const char *msg)
    {
        cout<<"Error : "<<msg<<endl;
    }
    return 0;
}
