/* Lab Program 12
   Write a C++ program to handle invalid input using a custom exception class.
   g++ -std=c++14 Lab12_ExceptionHandling.cpp -o lab12 */

#include<iostream>
using namespace std;

class invalidage
{
    public:
        void show()
        {
            cout<<"exception : age must be positive"<<endl;
        }
};

int main()
{
    int age;
    cout<<"Enter age : ";
    cin>>age;

    try
    {
        if(age <= 0)
            throw invalidage();
        cout<<"Age = "<<age<<endl;
    }
    catch(invalidage e)
    {
        e.show();
    }
    return 0;
}
