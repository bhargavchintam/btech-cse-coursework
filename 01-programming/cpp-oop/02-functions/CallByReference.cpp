// call by reference - swap works using reference parameters
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int x = 10, y = 20;
    cout<<"Before swap x = "<<x<<" y = "<<y<<endl;
    swap(x, y);
    cout<<"After swap x = "<<x<<" y = "<<y<<endl;
    return 0;
}
