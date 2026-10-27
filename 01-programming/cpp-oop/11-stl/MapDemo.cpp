// word count using map
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> count;
    string word;

    cout<<"enter words (type end to stop) :"<<endl;
    while(cin>>word)
    {
        if(word=="end")
            break;
        count[word]++;
    }

    cout<<"word frequency :"<<endl;
    map<string,int>::iterator it;
    for(it=count.begin();it!=count.end();it++)
        cout<<it->first<<" -> "<<it->second<<endl;

    return 0;
}
