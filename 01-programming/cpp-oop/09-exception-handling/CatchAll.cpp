#include<iostream>
using namespace std;

int main()
{
    int choice;
    cout<<"Enter 1 or 2 : ";
    cin>>choice;
    try
    {
        if(choice==1)
            throw 99;
        else
            throw 4.5;
    }
    catch(...)
    {
        cout<<"caught an exception, type does not matter here"<<endl;
    }
    return 0;
}
