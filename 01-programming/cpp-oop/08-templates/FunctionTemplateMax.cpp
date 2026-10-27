#include<iostream>
using namespace std;

template<class T>
T maximum(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int a, b;
    cout<<"Enter two integers : ";
    cin>>a>>b;
    cout<<"Max = "<<maximum(a, b)<<endl;

    double x, y;
    cout<<"Enter two doubles : ";
    cin>>x>>y;
    cout<<"Max = "<<maximum(x, y)<<endl;

    return 0;
}
