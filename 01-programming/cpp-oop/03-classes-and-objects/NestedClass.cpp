// nested class

#include<iostream>
using namespace std;

class outer
{
    public:
        class inner
        {
            public:
                int value;
                void show()
                {
                    cout<<"Inner value = "<<value<<endl;
                }
        };
        inner ob;
};

int main()
{
    outer o;
    o.ob.value=25;
    o.ob.show();
    return 0;
}
