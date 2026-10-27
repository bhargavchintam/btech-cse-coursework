// parameterized constructor

#include<iostream>
using namespace std;

class rectangle
{
    int length,breadth;
    public:
        rectangle(int l,int b)
        {
            length=l;
            breadth=b;
        }
        int area()
        {
            return length*breadth;
        }
};

int main()
{
    rectangle r(10,5);
    cout<<"Area = "<<r.area()<<endl;
    return 0;
}
