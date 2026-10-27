// sorting a vector using std::sort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(50);
    v.push_back(20);
    v.push_back(80);
    v.push_back(10);
    v.push_back(40);

    sort(v.begin(),v.end());
    cout<<"ascending : ";
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;

    // descending using a lambda comparator
    sort(v.begin(),v.end(),[](int a,int b){ return a>b; });
    cout<<"descending : ";
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
