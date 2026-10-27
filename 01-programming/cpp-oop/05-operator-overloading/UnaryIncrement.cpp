// prefix increment operator overloading

#include<iostream>
using namespace std;

class counter
{
    int count;
public:
    counter()
    {
        count = 0;
    }
    void operator++()
    {
        count++;
    }
    void display()
    {
        cout<<"count = "<<count<<endl;
    }
};

int main()
{
    counter c;
    c.display();
    ++c;
    ++c;
    ++c;
    c.display();
    return 0;
}
