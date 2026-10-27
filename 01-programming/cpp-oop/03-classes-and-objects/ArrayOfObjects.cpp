// array of objects

#include<iostream>
using namespace std;

class student
{
    int rollno;
    char name[20];
    float marks;
    public:
        void getdata()
        {
            cin>>rollno>>name>>marks;
        }
        void putdata()
        {
            cout<<rollno<<"\t"<<name<<"\t"<<marks<<"\n";
        }
};

int main()
{
    int n;
    cout<<"How many students ? ";
    cin>>n;
    student s[50];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of student "<<i+1<<" : ";
        s[i].getdata();
    }
    cout<<"\nStudent details\n";
    for(int i=0;i<n;i++)
        s[i].putdata();
    return 0;
}
