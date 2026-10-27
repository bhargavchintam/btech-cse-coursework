/* Lab Program 14
   Write a C++ program to write n student objects to a binary file and read them back.
   g++ -std=c++14 Lab14_FileObjectRecords.cpp -o lab14 */

#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int rollno;
    char name[20];
    float marks;
    public:
        void read()
        {
            cin>>rollno>>name>>marks;
        }
        void show()
        {
            cout<<rollno<<"\t"<<name<<"\t"<<marks<<endl;
        }
};

int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;

    student s;
    ofstream fout("students.dat", ios::binary);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter rollno name marks : ";
        s.read();
        fout.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    fout.close();

    ifstream fin("students.dat", ios::binary);
    cout<<"\nRollno\tName\tMarks\n";
    while(fin.read(reinterpret_cast<char*>(&s), sizeof(s)))
        s.show();
    fin.close();
    return 0;
}
