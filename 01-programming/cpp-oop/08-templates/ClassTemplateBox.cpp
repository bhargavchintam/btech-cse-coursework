// class template - Box holds any type
#include<iostream>
using namespace std;

template<class T>
class Box
{
    T value;
    public:
        void set(T v)
        {
            value = v;
        }
        T get()
        {
            return value;
        }
};

int main()
{
    Box<int> b1;
    b1.set(100);
    cout<<"int box = "<<b1.get()<<endl;

    Box<double> b2;
    b2.set(3.14);
    cout<<"double box = "<<b2.get()<<endl;

    Box<char> b3;
    b3.set('A');
    cout<<"char box = "<<b3.get()<<endl;

    return 0;
}
