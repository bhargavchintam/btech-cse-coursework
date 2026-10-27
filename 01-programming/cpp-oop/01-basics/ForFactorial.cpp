// factorial using for loop
#include<iostream>
using namespace std;

int main()
{
    int n;
    long fact = 1;
    cout<<"Enter a number : ";
    cin>>n;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    cout<<"Factorial of "<<n<<" = "<<fact<<endl;
    return 0;
}
