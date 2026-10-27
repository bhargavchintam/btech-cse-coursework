#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int rollno;
    char name[20];
    float marks;
public:
    void getdata()
    {
        cout<<"Enter rollno, name and marks : ";
        cin>>rollno>>name>>marks;
    }
    void putdata()
    {
        cout<<rollno<<"  "<<name<<"  "<<marks<<endl;
    }
};

int main()
{
    student s;
    ifstream fin("student.dat",ios::binary);
    if(!fin)
    {
        cout<<"file not found"<<endl;
        return 1;
    }
    fin.read(reinterpret_cast<char*>(&s),sizeof(s));
    cout<<"Student record read from file :"<<endl;
    s.putdata();
    fin.close();
    return 0;
}
