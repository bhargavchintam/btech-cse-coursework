// constructor with member initialization list

#include<iostream>
using namespace std;

class point
{
    int x,y;
    public:
        point(int a,int b):x(a),y(b)
        {
        }
        void show()
        {
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
};

int main()
{
    point p(3,7);
    cout<<"Point = ";
    p.show();
    return 0;
}
