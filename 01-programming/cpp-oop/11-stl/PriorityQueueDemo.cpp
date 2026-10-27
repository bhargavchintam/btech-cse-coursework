// priority queue - max heap by default
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout<<"max first : ";
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // min heap using greater
    priority_queue<int, vector<int>, greater<int> > minpq;
    minpq.push(30);
    minpq.push(10);
    minpq.push(50);
    minpq.push(20);

    cout<<"min first : ";
    while(!minpq.empty())
    {
        cout<<minpq.top()<<" ";
        minpq.pop();
    }
    cout<<endl;

    return 0;
}
