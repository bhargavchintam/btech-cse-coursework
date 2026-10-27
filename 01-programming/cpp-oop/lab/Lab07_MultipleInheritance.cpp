/* Lab Program 7
   Write a C++ program to demonstrate multiple inheritance.
   g++ -std=c++14 Lab07_MultipleInheritance.cpp -o lab07 */

#include<iostream>
using namespace std;

class student
{
    protected:
        int rollno;
    public:
        void getroll()
        {
            cout<<"Enter rollno : ";
            cin>>rollno;
        }
};

class marks
{
    protected:
        int m1, m2;
    public:
        void getmarks()
        {
            cout<<"Enter two subject marks : ";
            cin>>m1>>m2;
        }
};

class result : public student, public marks
{
    public:
        void display()
        {
            cout<<"Rollno : "<<rollno<<endl;
            cout<<"Total  : "<<m1+m2<<endl;
        }
};

int main()
{
    result r;
    r.getroll();
    r.getmarks();
    r.display();
    return 0;
}
