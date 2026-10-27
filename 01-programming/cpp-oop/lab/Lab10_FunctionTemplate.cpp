/* Lab Program 10
   Write a C++ program to implement generic swap and maximum using function templates.
   g++ -std=c++14 Lab10_FunctionTemplate.cpp -o lab10 */

#include<iostream>
using namespace std;

template<class T>
void myswap(T &a, T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
}

template<class T>
T mymax(T a, T b)
{
    return a>b ? a : b;
}

int main()
{
    int x, y;
    cout<<"Enter two integers : ";
    cin>>x>>y;
    myswap(x,y);
    cout<<"After swap : "<<x<<" "<<y<<endl;
    cout<<"Max = "<<mymax(x,y)<<endl;

    float p, q;
    cout<<"Enter two floats : ";
    cin>>p>>q;
    cout<<"Max = "<<mymax(p,q)<<endl;
    return 0;
}
