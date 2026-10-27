#include<iostream>
using namespace std;

template<class T>
class Stack
{
    T arr[100];
    int top;
    public:
        Stack()
        {
            top = -1;
        }
        void push(T x)
        {
            if(top == 99)
            {
                cout<<"stack full"<<endl;
                return;
            }
            arr[++top] = x;
        }
        T pop()
        {
            return arr[top--];
        }
        bool isEmpty()
        {
            return top == -1;
        }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.isEmpty())
        cout<<s.pop()<<" ";
    cout<<endl;

    return 0;
}
