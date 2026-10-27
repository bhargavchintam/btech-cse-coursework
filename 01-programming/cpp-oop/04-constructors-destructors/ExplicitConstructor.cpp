// explicit constructor

#include<iostream>
using namespace std;

class Distance
{
    int meter;
    public:
        explicit Distance(int m)
        {
            meter=m;
        }
        void show()
        {
            cout<<"Distance = "<<meter<<" m"<<endl;
        }
};

int main()
{
    Distance d(100);
    d.show();
    return 0;
}
