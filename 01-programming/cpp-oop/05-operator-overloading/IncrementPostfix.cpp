// postfix increment operator overloading

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
    counter(int c)
    {
        count = c;
    }
    counter operator++(int)
    {
        counter temp;
        temp.count = count;
        count++;
        return temp;      // returns old value
    }
    void display()
    {
        cout<<"count = "<<count<<endl;
    }
};

int main()
{
    counter c(5), old;
    old = c++;
    cout<<"after c++  "; c.display();
    cout<<"old value  "; old.display();
    return 0;
}
