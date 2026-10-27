// using find, count and accumulate algorithms
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(5);
    v.push_back(20);
    v.push_back(5);
    v.push_back(15);

    int key = 5;
    vector<int>::iterator it = find(v.begin(),v.end(),key);
    if(it!=v.end())
        cout<<key<<" found at position "<<(it-v.begin())<<endl;
    else
        cout<<key<<" not found"<<endl;

    int c = count(v.begin(),v.end(),5);
    cout<<"count of 5 = "<<c<<endl;

    int sum = accumulate(v.begin(),v.end(),0);
    cout<<"sum of all = "<<sum<<endl;

    return 0;
}
