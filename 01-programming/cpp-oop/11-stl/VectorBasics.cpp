// basic operations on vector
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    cout<<"size = "<<v.size()<<endl;

    cout<<"using index :"<<endl;
    int n = v.size();
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

    cout<<"using range for :"<<endl;
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;

    v.pop_back();
    cout<<"after pop_back size = "<<v.size()<<endl;
    cout<<"front = "<<v.front()<<"  back = "<<v.back()<<endl;

    return 0;
}
