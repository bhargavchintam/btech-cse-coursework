// multiple inheritance

#include<iostream>
using namespace std;

class father
{
public:
    void height()
    {
        cout<<"height inherited from father"<<endl;
    }
};

class mother
{
public:
    void colour()
    {
        cout<<"colour inherited from mother"<<endl;
    }
};

class child : public father, public mother
{
public:
    void show()
    {
        cout<<"child has features of both parents"<<endl;
    }
};

int main()
{
    child c;
    c.height();
    c.colour();
    c.show();
    return 0;
}
