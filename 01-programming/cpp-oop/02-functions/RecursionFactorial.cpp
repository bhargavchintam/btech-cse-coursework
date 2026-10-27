// factorial using recursion
#include<iostream>
using namespace std;

long fact(int n)
{
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Factorial = "<<fact(n)<<endl;
    return 0;
}
