// queue container adapter - FIFO
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);

    cout<<"front = "<<q.front()<<endl;
    cout<<"back = "<<q.back()<<endl;
    cout<<"size = "<<q.size()<<endl;

    cout<<"serving queue : ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
