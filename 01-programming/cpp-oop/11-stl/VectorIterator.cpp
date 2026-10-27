// traversing a vector using iterator
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=1;i<=5;i++)
        v.push_back(i*i);

    vector<int>::iterator it;
    cout<<"elements : ";
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    // insert 100 at second position
    it = v.begin();
    v.insert(it+1,100);

    cout<<"after insert : ";
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<" ";
    cout<<endl;

    v.erase(v.begin());
    cout<<"after erase first : ";
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
