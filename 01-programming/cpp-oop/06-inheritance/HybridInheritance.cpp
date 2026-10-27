// hybrid inheritance

#include<iostream>
using namespace std;

class student
{
protected:
    int rollno;
public:
    void getnumber(int n)
    {
        rollno = n;
    }
    void putnumber()
    {
        cout<<"roll no : "<<rollno<<endl;
    }
};

class test : public student
{
protected:
    float part1, part2;
public:
    void getmarks(float a, float b)
    {
        part1 = a;
        part2 = b;
    }
    void putmarks()
    {
        cout<<"marks obtained : "<<part1<<" and "<<part2<<endl;
    }
};

class sports
{
protected:
    float score;
public:
    void getscore(float s)
    {
        score = s;
    }
    void putscore()
    {
        cout<<"sports score : "<<score<<endl;
    }
};

class result : public test, public sports
{
    float total;
public:
    void display()
    {
        total = part1 + part2 + score;
        putnumber();
        putmarks();
        putscore();
        cout<<"total score : "<<total<<endl;
    }
};

int main()
{
    result r;
    r.getnumber(200);
    r.getmarks(30, 35);
    r.getscore(7);
    r.display();
    return 0;
}
