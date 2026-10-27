// multimap allows duplicate keys, also using pair
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    multimap<string,string> mm;
    mm.insert(pair<string,string>("cse","rahul"));
    mm.insert(pair<string,string>("cse","priya"));
    mm.insert(pair<string,string>("ece","arjun"));
    mm.insert(pair<string,string>("cse","meena"));
    mm.insert(pair<string,string>("ece","kiran"));

    cout<<"branch wise students :"<<endl;
    multimap<string,string>::iterator it;
    for(it=mm.begin();it!=mm.end();it++)
        cout<<it->first<<" : "<<it->second<<endl;

    cout<<"number of cse students = "<<mm.count("cse")<<endl;

    return 0;
}
