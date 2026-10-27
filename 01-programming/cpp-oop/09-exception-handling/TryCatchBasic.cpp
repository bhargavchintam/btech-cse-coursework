// divide two numbers, throw if denominator is zero
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    try
    {
        if(b==0)
            throw b;
        cout<<"Result = "<<a/b<<endl;
    }
    catch(int x)
    {
        cout<<"Exception caught : division by zero"<<endl;
    }
    cout<<"end of program"<<endl;
    return 0;
}
