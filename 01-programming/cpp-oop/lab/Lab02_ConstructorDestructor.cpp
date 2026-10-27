/* Lab Program 2
   Write a C++ program to demonstrate a parameterized constructor and a destructor with messages.
   g++ -std=c++14 Lab02_ConstructorDestructor.cpp -o lab02 */

#include<iostream>
using namespace std;

class item
{
    int code;
    float price;
    public:
        item(int c, float p)
        {
            code = c;
            price = p;
            cout<<"constructor called for item "<<code<<endl;
        }
        void show()
        {
            cout<<"Code = "<<code<<"  Price = "<<price<<endl;
        }
        ~item()
        {
            cout<<"destructor called for item "<<code<<endl;
        }
};

int main()
{
    item a(101,25.5);
    item b(102,40.0);
    a.show();
    b.show();
    return 0;
}
