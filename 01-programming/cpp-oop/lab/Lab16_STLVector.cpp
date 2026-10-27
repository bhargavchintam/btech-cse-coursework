/* Lab Program 16
   Write a C++ program to store student marks in a vector and sort them.
   g++ -std=c++14 Lab16_STLVector.cpp -o lab16 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;

    vector<int> marks(n);
    cout<<"Enter marks : ";
    for(int i=0;i<n;i++)
        cin>>marks[i];

    sort(marks.begin(), marks.end());

    cout<<"Marks in sorted order : ";
    for(auto m : marks)
        cout<<m<<" ";
    cout<<endl;
    return 0;
}
