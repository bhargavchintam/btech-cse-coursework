/* Lab Program 4
   Write a C++ program to add two objects using a friend function.
   g++ -std=c++14 Lab04_FriendFunction.cpp -o lab04 */

#include<iostream>
using namespace std;

class number
{
    int value;
    public:
        void read()
        {
            cin>>value;
        }
        friend int add(number, number);   // friend can access private
};

int add(number a, number b)
{
    return a.value + b.value;
}

int main()
{
    number n1, n2;
    cout<<"Enter two numbers : ";
    n1.read();
    n2.read();
    cout<<"Sum = "<<add(n1,n2)<<endl;
    return 0;
}
