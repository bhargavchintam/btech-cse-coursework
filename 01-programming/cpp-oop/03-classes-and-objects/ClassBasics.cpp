#include<iostream>
using namespace std;

class student
{
    private:
        int rollno;
        char name[20];
        float marks;
    public:
        void getdata()
        {
            cout<<"Enter rollno : ";
            cin>>rollno;
            cout<<"Enter name : ";
            cin>>name;
            cout<<"Enter marks : ";
            cin>>marks;
        }
        void putdata()
        {
            cout<<"Rollno : "<<rollno<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Marks : "<<marks<<endl;
        }
};

int main()
{
    student s;
    s.getdata();
    s.putdata();
    return 0;
}
