#include<iostream>
using namespace std;

template<class T1, class T2>
class Pair
{
    T1 first;
    T2 second;
    public:
        Pair(T1 a, T2 b)
        {
            first = a;
            second = b;
        }
        void show()
        {
            cout<<"("<<first<<", "<<second<<")"<<endl;
        }
};

int main()
{
    Pair<int, double> p1(5, 2.5);
    Pair<char, int> p2('A', 65);
    Pair<int, char> p3(1, 'z');

    p1.show();
    p2.show();
    p3.show();

    return 0;
}
