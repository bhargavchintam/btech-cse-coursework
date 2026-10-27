// constructor and destructor

#include<iostream>
using namespace std;

class test
{
    public:
        test()
        {
            cout<<"Constructor called"<<endl;
        }
        ~test()
        {
            cout<<"Destructor called"<<endl;
        }
};

int main()
{
    cout<<"Main begins"<<endl;
    test t;
    cout<<"Main ends"<<endl;
    return 0;
}
