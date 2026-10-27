// unary minus operator overloading

#include<iostream>
using namespace std;

class space
{
    int x, y;
public:
    void getdata(int a, int b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
    void operator-();
};

void space::operator-()
{
    x = -x;
    y = -y;
}

int main()
{
    space s;
    s.getdata(10, -20);
    cout<<"before negation : ";
    s.display();
    -s;
    cout<<"after negation : ";
    s.display();
    return 0;
}
