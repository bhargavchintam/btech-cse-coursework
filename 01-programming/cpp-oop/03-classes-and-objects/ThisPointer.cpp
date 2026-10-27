// use of this pointer

#include<iostream>
using namespace std;

class sample
{
    int x;
    public:
        void setx(int x)
        {
            this->x=x;    // this is the calling object
        }
        void show()
        {
            cout<<"x = "<<this->x<<endl;
        }
};

int main()
{
    sample s;
    s.setx(50);
    s.show();
    return 0;
}
