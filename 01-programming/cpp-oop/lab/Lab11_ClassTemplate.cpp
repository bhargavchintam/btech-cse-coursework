/* Lab Program 11
   Write a C++ program to implement a generic stack using a class template.
   g++ -std=c++14 Lab11_ClassTemplate.cpp -o lab11 */

#include<iostream>
using namespace std;

template<class T>
class Stack
{
    T a[10];
    int top;
    public:
        Stack()
        {
            top = -1;
        }
        void push(T x)
        {
            if(top == 9)
            {
                cout<<"stack full"<<endl;
                return;
            }
            a[++top] = x;
        }
        void pop()
        {
            if(top == -1)
            {
                cout<<"stack empty"<<endl;
                return;
            }
            cout<<"popped "<<a[top--]<<endl;
        }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
