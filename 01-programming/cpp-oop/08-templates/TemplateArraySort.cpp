#include<iostream>
using namespace std;

template<class T>
void bubbleSort(T a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                T t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

template<class T>
void display(T a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[] = {5, 2, 9, 1, 3};
    bubbleSort(a, 5);
    display(a, 5);

    double b[] = {3.3, 1.1, 2.2, 0.5};
    bubbleSort(b, 4);
    display(b, 4);

    return 0;
}
