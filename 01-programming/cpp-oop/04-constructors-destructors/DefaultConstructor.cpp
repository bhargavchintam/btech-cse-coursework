// default constructor

#include<iostream>
using namespace std;

class number
{
    int n;
    public:
        number()
        {
            n=0;
        }
        void show()
        {
            cout<<"n = "<<n<<endl;
        }
};

int main()
{
    number a;
    a.show();
    return 0;
}
