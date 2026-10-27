// double ended queue
#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout<<"deque : ";
    for(int i=0;i<(int)dq.size();i++)
        cout<<dq[i]<<" ";
    cout<<endl;

    cout<<"front = "<<dq.front()<<endl;
    cout<<"back = "<<dq.back()<<endl;

    dq.pop_front();
    dq.pop_back();

    cout<<"after pop front and back : ";
    for(auto x : dq)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
