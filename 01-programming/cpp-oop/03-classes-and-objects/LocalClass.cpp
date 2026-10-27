// local class defined inside a function

#include<iostream>
using namespace std;

void test()
{
    class local
    {
        int x;
        public:
            void setx(int a)
            {
                x=a;
            }
            void show()
            {
                cout<<"x = "<<x<<endl;
            }
    };
    local l;
    l.setx(10);
    l.show();
}

int main()
{
    test();
    return 0;
}
