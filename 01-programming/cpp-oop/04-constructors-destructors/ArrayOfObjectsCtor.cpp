// array of objects with constructor

#include<iostream>
using namespace std;

class student
{
    int rollno;
    public:
        student()
        {
            rollno=0;
        }
        void setrollno(int r)
        {
            rollno=r;
        }
        void show()
        {
            cout<<"Rollno = "<<rollno<<endl;
        }
};

int main()
{
    student s[3];
    for(int i=0;i<3;i++)
        s[i].setrollno(101+i);
    for(int i=0;i<3;i++)
        s[i].show();
    return 0;
}
