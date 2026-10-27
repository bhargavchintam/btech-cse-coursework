/* Lab Program 5
   Write a C++ program to overload the unary minus operator to negate the coordinates of a point.
   g++ -std=c++14 Lab05_OperatorOverloadUnary.cpp -o lab05 */

#include<iostream>
using namespace std;

class point
{
    int x, y, z;
    public:
        void read()
        {
            cin>>x>>y>>z;
        }
        void operator-()
        {
            x = -x;
            y = -y;
            z = -z;
        }
        void show()
        {
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
};

int main()
{
    point p;
    cout<<"Enter x y z : ";
    p.read();
    -p;
    cout<<"After negation : ";
    p.show();
    return 0;
}
