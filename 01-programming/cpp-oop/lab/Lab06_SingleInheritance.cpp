/* Lab Program 6
   Write a C++ program to demonstrate single inheritance.
   g++ -std=c++14 Lab06_SingleInheritance.cpp -o lab06 */

#include<iostream>
using namespace std;

class person
{
    protected:
        char name[20];
        int age;
    public:
        void getdata()
        {
            cout<<"Enter name and age : ";
            cin>>name>>age;
        }
};

class student : public person
{
    int marks;
    public:
        void getmarks()
        {
            cout<<"Enter marks : ";
            cin>>marks;
        }
        void display()
        {
            cout<<name<<"\t"<<age<<"\t"<<marks<<endl;
        }
};

int main()
{
    student s;
    s.getdata();
    s.getmarks();
    cout<<"\nName\tAge\tMarks\n";
    s.display();
    return 0;
}
