// write n student objects to a file then read all of them back
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
    int n;
    student s;
    cout<<"How many students ? ";
    cin>>n;

    ofstream fout("students.dat",ios::binary);
    for(int i=0;i<n;i++)
    {
        s.getdata();
        fout.write(reinterpret_cast<char*>(&s),sizeof(s));
    }
    fout.close();

    ifstream fin("students.dat",ios::binary);
    cout<<"\nAll records :"<<endl;
    while(fin.read(reinterpret_cast<char*>(&s),sizeof(s)))
    {
        s.putdata();
    }
    fin.close();
    return 0;
}
