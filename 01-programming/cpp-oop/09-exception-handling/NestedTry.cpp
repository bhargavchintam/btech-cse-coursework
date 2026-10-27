#include<iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            cout<<"inner try block"<<endl;
            throw 10;
        }
        catch(char c)
        {
            cout<<"inner catch (char)"<<endl;
        }
    }
    catch(int x)
    {
        cout<<"outer catch (int) = "<<x<<endl;
    }
    return 0;
}
