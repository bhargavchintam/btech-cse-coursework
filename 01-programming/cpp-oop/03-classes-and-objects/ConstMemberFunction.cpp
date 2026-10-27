// const member function

#include<iostream>
using namespace std;

class circle
{
    float radius;
    public:
        void setradius(float r)
        {
            radius=r;
        }
        float area() const
        {
            return 3.14*radius*radius;
        }
};

int main()
{
    circle c;
    c.setradius(5);
    cout<<"Area = "<<c.area()<<endl;
    return 0;
}
