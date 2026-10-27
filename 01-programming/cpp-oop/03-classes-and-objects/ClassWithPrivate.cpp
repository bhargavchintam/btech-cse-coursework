#include<iostream>
using namespace std;

class student
{
    private:
        int rollno;
        float marks;
    public:
        void setRollno(int r)
        {
            rollno=r;
        }
        void setMarks(float m)
        {
            marks=m;
        }
        int getRollno()
        {
            return rollno;
        }
        float getMarks()
        {
            return marks;
        }
};

int main()
{
    student s;
    s.setRollno(101);
    s.setMarks(88.5);
    cout<<"Rollno = "<<s.getRollno()<<endl;
    cout<<"Marks = "<<s.getMarks()<<endl;
    return 0;
}
