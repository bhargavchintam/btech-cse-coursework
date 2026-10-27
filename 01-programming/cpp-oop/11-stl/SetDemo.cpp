// set stores unique elements in sorted order
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(40);
    s.insert(10);
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout<<"set elements : ";
    for(auto x : s)
        cout<<x<<" ";
    cout<<endl;

    cout<<"size = "<<s.size()<<endl;

    if(s.find(30)!=s.end())
        cout<<"30 is present"<<endl;
    else
        cout<<"30 not found"<<endl;

    s.erase(30);
    cout<<"after erasing 30 : ";
    for(auto x : s)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
