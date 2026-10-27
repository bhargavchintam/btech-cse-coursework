// virtual base class to solve the diamond problem

#include<iostream>
using namespace std;

class student
{
protected:
    int rollno;
public:
    void getroll(int r)
    {
        rollno = r;
    }
    void putroll()
    {
        cout<<"roll no : "<<rollno<<endl;
    }
};

class test : virtual public student
{
protected:
    float mark;
public:
    void getmark(float a)
    {
        mark = a;
    }
};

class sports : virtual public student
{
protected:
    float score;
public:
    void getscore(float s)
    {
        score = s;
    }
};

class result : public test, public sports
{
public:
    void display()
    {
        putroll();          // only one copy of rollno because student is virtual base
        cout<<"mark : "<<mark<<endl;
        cout<<"score : "<<score<<endl;
        cout<<"total : "<<mark + score<<endl;
    }
};

int main()
{
    result r;
    r.getroll(55);
    r.getmark(90);
    r.getscore(8);
    r.display();
    return 0;
}
