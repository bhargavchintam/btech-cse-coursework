// random access to records using seekg, seekp and tellg
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
    fstream file("record.dat",ios::in|ios::out|ios::binary|ios::trunc);

    for(int i=0;i<3;i++)
    {
        s.getdata();
        file.write(reinterpret_cast<char*>(&s),sizeof(s));
    }

    file.seekg(0,ios::end);
    int total=file.tellg()/sizeof(s);
    cout<<"Total records in file = "<<total<<endl;

    int rno;
    cout<<"Which record to read (1 to "<<total<<") ? ";
    cin>>rno;

    file.seekg((rno-1)*sizeof(s),ios::beg);
    file.read(reinterpret_cast<char*>(&s),sizeof(s));
    cout<<"Record "<<rno<<" : ";
    s.putdata();

    file.close();
    return 0;
}
