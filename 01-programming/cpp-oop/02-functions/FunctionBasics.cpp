// function prototype, definition and call
#include<iostream>
using namespace std;

int add(int, int);

int main()
{
    int a, b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    cout<<"Sum = "<<add(a, b)<<endl;
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
