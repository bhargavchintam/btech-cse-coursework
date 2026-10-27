// overloading assignment = operator

#include<iostream>
using namespace std;

class sample
{
    int a, b;
public:
    sample() { }
    sample(int x, int y)
    {
        a = x;
        b = y;
    }
    void operator=(sample s)
    {
        a = s.a;
        b = s.b;
    }
    void display()
    {
        cout<<"a = "<<a<<"  b = "<<b<<endl;
    }
};

int main()
{
    sample s1(10, 20), s2;
    s2 = s1;
    cout<<"s1 : "; s1.display();
    cout<<"s2 : "; s2.display();
    return 0;
}
