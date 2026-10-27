#include<iostream>
using namespace std;

void check(int n)
{
    try
    {
        if(n==0)
            throw n;
        cout<<"inside function, value is fine"<<endl;
    }
    catch(int)
    {
        cout<<"caught in function, rethrowing to caller"<<endl;
        throw;
    }
}

int main()
{
    try
    {
        check(0);
    }
    catch(int)
    {
        cout<<"caught again in main"<<endl;
    }
    return 0;
}
