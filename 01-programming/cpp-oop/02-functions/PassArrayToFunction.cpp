#include<iostream>
using namespace std;

int sum(int a[], int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
        s = s + a[i];
    return s;
}

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    cout<<"Sum of array = "<<sum(a, 5)<<endl;
    return 0;
}
