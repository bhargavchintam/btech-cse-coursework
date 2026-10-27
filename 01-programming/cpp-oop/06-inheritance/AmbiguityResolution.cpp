// resolving ambiguity of same name members using scope resolution

#include<iostream>
using namespace std;

class first
{
public:
    void show()
    {
        cout<<"show of first class"<<endl;
    }
};

class second
{
public:
    void show()
    {
        cout<<"show of second class"<<endl;
    }
};

class third : public first, public second
{
public:
    void display()
    {
        first::show();       // scope resolution removes the ambiguity
        second::show();
    }
};

int main()
{
    third t;
    t.display();
    return 0;
}
