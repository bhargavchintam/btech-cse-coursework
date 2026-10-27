// static local variable retains its value between calls
#include<iostream>
using namespace std;

void counter()
{
    static int count = 0;
    count++;
    cout<<"Called "<<count<<" time(s)"<<endl;
}

int main()
{
    counter();
    counter();
    counter();
    return 0;
}
