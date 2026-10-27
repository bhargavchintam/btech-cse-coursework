// writing a single object to a binary file
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
    s.getdata();
    ofstream fout("student.dat",ios::binary);
    fout.write(reinterpret_cast<char*>(&s),sizeof(s));
    fout.close();
    cout<<"object written to file"<<endl;
    return 0;
}
