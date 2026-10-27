// multilevel inheritance

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

class test : public student
{
protected:
    float m1, m2;
public:
    void getmarks(float a, float b)
    {
        m1 = a;
        m2 = b;
    }
    void putmarks()
    {
        cout<<"marks : "<<m1<<" "<<m2<<endl;
    }
};

class result : public test
{
    float total;
public:
    void display()
    {
        total = m1 + m2;
        putroll();
        putmarks();
        cout<<"total : "<<total<<endl;
    }
};

int main()
{
    result r;
    r.getroll(101);
    r.getmarks(78, 85);
    r.display();
    return 0;
}
