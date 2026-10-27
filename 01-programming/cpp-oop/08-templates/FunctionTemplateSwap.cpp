#include<iostream>
using namespace std;

template<class T>
void swapValues(T &a, T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int x = 5, y = 10;
    swapValues(x, y);
    cout<<"x = "<<x<<" y = "<<y<<endl;

    double p = 1.5, q = 2.5;
    swapValues(p, q);
    cout<<"p = "<<p<<" q = "<<q<<endl;

    return 0;
}
