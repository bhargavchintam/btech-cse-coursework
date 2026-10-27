#include<iostream>
using namespace std;

void test(int n)
{
    try
    {
        if(n==1)
            throw 100;
        else if(n==2)
            throw 'x';
        else
            throw 3.14;
    }
    catch(int i)
    {
        cout<<"caught an int = "<<i<<endl;
    }
    catch(char c)
    {
        cout<<"caught a char = "<<c<<endl;
    }
    catch(...)
    {
        cout<<"caught some other type"<<endl;
    }
}

int main()
{
    test(1);
    test(2);
    test(3);
    return 0;
}
