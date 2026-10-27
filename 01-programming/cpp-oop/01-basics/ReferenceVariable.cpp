// reference is an alias to another variable
#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    int &ref = x;            // ref and x share same memory

    cout<<"x = "<<x<<" ref = "<<ref<<endl;
    ref = 50;
    cout<<"After ref = 50"<<endl;
    cout<<"x = "<<x<<" ref = "<<ref<<endl;
    return 0;
}
