// list container operations
#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_front(10);
    l.push_back(40);

    cout<<"list : ";
    for(auto x : l)
        cout<<x<<" ";
    cout<<endl;

    l.sort();
    l.reverse();
    cout<<"after sort and reverse : ";
    for(auto x : l)
        cout<<x<<" ";
    cout<<endl;

    l.pop_front();
    l.pop_back();
    cout<<"after pop front and back : ";
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"size = "<<l.size()<<endl;

    return 0;
}
