#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"How many elements : ";
    cin>>n;

    int a[100];
    int sum = 0;
    cout<<"Enter "<<n<<" elements : ";
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum = sum + a[i];
    }

    cout<<"Sum = "<<sum<<endl;
    cout<<"Average = "<<(float)sum / n<<endl;
    return 0;
}
