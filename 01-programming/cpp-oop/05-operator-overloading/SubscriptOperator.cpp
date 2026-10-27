// overloading subscript [] operator for an array class

#include<iostream>
using namespace std;

class myarray
{
    int arr[5];
public:
    myarray()
    {
        for(int i = 0; i < 5; i++)
            arr[i] = 0;
    }
    int& operator[](int i)
    {
        return arr[i];
    }
};

int main()
{
    myarray a;
    for(int i = 0; i < 5; i++)
        a[i] = (i + 1) * 10;
    cout<<"array elements : ";
    for(int i = 0; i < 5; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
