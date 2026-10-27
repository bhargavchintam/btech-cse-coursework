// friend function adding data of two objects

#include<iostream>
using namespace std;

class number
{
    int n;
    public:
        void getdata()
        {
            cin>>n;
        }
        friend int add(number n1,number n2);    // friend can access private
};

int add(number n1,number n2)
{
    return n1.n+n2.n;
}

int main()
{
    number a,b;
    cout<<"Enter two values : ";
    a.getdata();
    b.getdata();
    cout<<"Sum = "<<add(a,b)<<endl;
    return 0;
}
