// student marks result using multilevel inheritance

#include<iostream>
using namespace std;

class student
{
protected:
    int rollno;
    char name[20];
public:
    void getstudent()
    {
        cout<<"enter roll no and name : ";
        cin>>rollno>>name;
    }
};

class marks : public student
{
protected:
    int m1, m2, m3;
public:
    void getmarks()
    {
        cout<<"enter marks of 3 subjects : ";
        cin>>m1>>m2>>m3;
    }
};

class result : public marks
{
    int total;
    float average;
public:
    void display()
    {
        total = m1 + m2 + m3;
        average = total / 3.0;
        cout<<"roll no : "<<rollno<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"total : "<<total<<endl;
        cout<<"average : "<<average<<endl;
        if(average >= 35)
            cout<<"result : pass"<<endl;
        else
            cout<<"result : fail"<<endl;
    }
};

int main()
{
    result r;
    r.getstudent();
    r.getmarks();
    r.display();
    return 0;
}
