/* Bindu Bhargava  05-11-19 */
#include<iostream>
using namespace std;

class shape
{
    public:
        virtual void draw()
        {
            cout<<"drawing a shape"<<endl;
        }
};

class circle : public shape
{
    public:
        void draw()
        {
            cout<<"drawing a circle"<<endl;
        }
};

class square : public shape
{
    public:
        void draw()
        {
            cout<<"drawing a square"<<endl;
        }
};

void render(shape &s)
{
    s.draw();
}

int main()
{
    circle c;
    square sq;
    render(c);
    render(sq);
    return 0;
}
