// member functions defined outside the class

#include<iostream>
using namespace std;

class student
{
    int rollno;
    char name[20];
    float marks;
    public:
        void getdata();
        void putdata();
};

void student::getdata()
{
    cout<<"Enter rollno, name and marks : ";
    cin>>rollno>>name>>marks;
}

void student::putdata()
{
    cout<<rollno<<"  "<<name<<"  "<<marks<<endl;
}

int main()
{
    student s;
    s.getdata();
    s.putdata();
    return 0;
}
