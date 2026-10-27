// stack container adapter - LIFO
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"top = "<<s.top()<<endl;
    cout<<"size = "<<s.size()<<endl;

    cout<<"popping all : ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    cout<<"empty now ? "<<(s.empty() ? "yes" : "no")<<endl;

    return 0;
}
