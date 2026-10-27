#include<iostream>
using namespace std;

template<class T1, class T2>
void display(T1 a, T2 b)
{
    cout<<a<<" and "<<b<<endl;
}

int main()
{
    display(10, 3.14);
    display('A', "hello");
    display(5, 'z');
    //display(1.5, 2);
    return 0;
}
