/* Lab Program 1
   Write a C++ program to define a class student, read details of n students and display them.
   g++ -std=c++14 Lab01_ClassObject.cpp -o lab01 */

#include<iostream>
using namespace std;

class student
{
    private:
        int rollno;
        char name[20];
        float marks;
    public:
        void read()
        {
            cout<<"Enter rollno, name and marks : ";
            cin>>rollno>>name>>marks;
        }
        void display()
        {
            cout<<rollno<<"\t"<<name<<"\t"<<marks<<endl;
        }
};

int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;

    student s[50];
    for(int i=0;i<n;i++)
        s[i].read();

    cout<<"\nRollno\tName\tMarks\n";
    for(int i=0;i<n;i++)
        s[i].display();
    return 0;
}
