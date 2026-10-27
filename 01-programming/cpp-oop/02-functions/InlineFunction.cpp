#include<iostream>
using namespace std;

inline int cube(int x)
{
    return x * x * x;
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Cube = "<<cube(n)<<endl;
    return 0;
}
